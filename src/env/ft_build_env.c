/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_build_env.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoussas <mhoussas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 12:03:27 by mhoussas          #+#    #+#             */
/*   Updated: 2025/03/09 14:53:43 by mhoussas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

static char	*ft_local_strdup(char *s)
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
		ft_lstadd_back(&lst, ft_lstnew(ft_local_strdup("PATH"), ft_local_strdup("/mnt/homes/mhoussas/.docker/bin:/usr/gnu/bin:/usr/local/bin:/bin:/usr/bin:.")));
	else if (ft_strncmp(s, "PATH=/mnt/homes/mhoussas/.docker/bin:", 39))
		ft_lstadd_back(&lst, ft_lstnew(ft_local_strdup("PATH"), ft_strjoin("/mnt/homes/mhoussas/.docker/bin:", s + 5)));
	else
	{
		var = ft_export_split(s);
		ft_lstadd_back(&lst, ft_lstnew(ft_local_strdup(var[0]), ft_local_strdup(var[1])));
	}
	ft_lstlast(lst)->active = 1;
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

	var = ft_export_split(aid);
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
	ft_lstadd_back(&lst, ft_lstnew(aid));
}

t_list	*ft_build_env(char **env)
{
	t_list	*lst;

	lst = NULL;
	while (env && *env)
	{
		if (!ft_strncmp(*env, "PATH=", 5) || !ft_strncmp(*env, "PATH", 5))
			ft_path_var(&lst, *env);
		else if (!ft_strncmp(*env, "_=", 2) || !ft_strncmp(*env, "_", 2))
			ft_lstadd_back(&lst, ft_lstnew(ft_local_strdup("_=/usr/bin/env")));
		else if (!ft_strncmp(*env, "SHLVL", 5) || !ft_strncmp(*env, "SHLVL=", 5))
			ft_shlv_var(lst, *env);
		else if (!ft_strncmp(*env, "OLDPWD", 6) || !ft_strncmp(*env, "OLDPWD=", 6))
			ft_lstadd_back(&lst, ft_lstnew("OLDPWD"));
		else if (!ft_strncmp(*env, "PWD", 4) || !ft_strncmp(*env, "PWD=", 4))
			ft_lstadd_back(&lst, ft_lstnew(ft_strjoin("PWD=", getcwd(NULL, 0))));
		else
			ft_lstadd_back(&lst, ft_lstnew(ft_local_strdup(*env)));
		lst->active = !!ft_strchr(ft_lstlast(lst)->content, '=');
	}
	return (lst);
}
