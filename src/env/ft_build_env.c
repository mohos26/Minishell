/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_build_env.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoussas <mhoussas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 12:03:27 by mhoussas          #+#    #+#             */
/*   Updated: 2025/03/10 11:00:38 by mhoussas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

char	*ft_local_strdup(char *s)
{
	char	*ptr;
	char	*head;

	ptr = malloc(ft_strlen(s) * sizeof(char) + 1);
	if (!ptr)
		ft_exit(1);
	head = ptr;
	while (*s)
		*ptr++ = *s++;
	*ptr = '\0';
	return (head);
}

static void	ft_path_var(t_list *lst, char *s)
{
	char	**var;

	if (!ft_strncmp(s, "PATH", 5))
		ft_lstadd_back(&lst, ft_lstnew(ft_local_strdup("PATH"),
				ft_local_strdup("/mnt/homes/mhoussas/.docker/bin:/usr/gnu/bin:\
				/usr/local/bin:/bin:/usr/bin:."), 1));
	else if (ft_strncmp(s, "PATH=/mnt/homes/mhoussas/.docker/bin:", 39))
		ft_lstadd_back(&lst, ft_lstnew(ft_local_strdup("PATH"),
				ft_local_strdup(ft_strjoin("/mnt/homes/mhoussas/.docker/bin:",
						s + 5)), 1));
	else
	{
		var = ft_export_split(s);
		ft_lstadd_back(&lst, ft_lstnew(ft_local_strdup(var[0]),
				ft_local_strdup(var[1]), 1));
	}
}

static int	ft_is_number(char *s)
{
	int	len;

	len = 0;
	if (*s == '+' || *s == '-')
		s++;
	if (!*s)
		return (0);
	while (len++ < 3 && ft_isdigit(*s))
		s++;
	return (!*s);
}

static void	ft_shlv_var(t_list *lst, char *s)
{
	char	**var;
	int		n;
	char	*aid;

	var = ft_export_split(s);
	if (ft_is_number(var[1]))
	{
		n = ft_atoi(var[1]);
		if (n == 999)
			aid = ft_strdup("SHLVL=");
		else
		{
			if (n < 0)
				aid = ft_strdup("SHLVL=0");
			else
				aid = ft_strjoin("SHLVL=", ft_itoa(n + 1));
		}
	}
	else
		aid = ft_strdup("SHLVL=1");
	var = ft_export_split(aid);
	ft_lstadd_back(&lst, ft_lstnew(ft_local_strdup(var[0]),
			ft_local_strdup(var[1]), 1));
}

t_list	*ft_build_env(char **env)
{
	t_list	*lst;
	char	**var;

	lst = NULL;
	while (env && *env)
	{
		var = ft_export_split(*env);
		if (!ft_strncmp(var[0], "PATH", 5))
			ft_path_var(lst, *env);
		else if (!ft_strncmp(var[0], "_", 2))
			ft_lstadd_back(&lst, ft_lstnew(ft_local_strdup("_"),
					ft_local_strdup("/usr/bin/env"), 1));
		else if (!ft_strncmp(var[0], "SHLVL", 6))
			ft_shlv_var(lst, *env);
		else if (!ft_strncmp(var[0], "OLDPWD", 7))
			ft_lstadd_back(&lst, ft_lstnew(ft_local_strdup("OLDPWD"), NULL, 0));
		else if (!ft_strncmp(var[0], "PWD", 4))
			ft_lstadd_back(&lst, ft_lstnew(ft_local_strdup("PWD"),
					ft_local_strdup(getcwd(NULL, 0)), 1));
		else
			ft_lstadd_back(&lst, ft_lstnew(ft_local_strdup(var[0]),
					ft_local_strdup(var[1]), !!ft_strchr(*env, '=')));
		env++;
	}
	return (lst);
}
