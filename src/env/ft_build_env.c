/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_build_env.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoussas <mhoussas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 12:03:27 by mhoussas          #+#    #+#             */
/*   Updated: 2025/05/03 16:33:21 by mhoussas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

static t_env	*ft_path_var(t_env *lst, char *s)
{
	char	**var;

	if (!s)
		ft_lstadd_back_env(&lst, ft_lstnew_env(ft_env_strdup("PATH"),
				ft_env_strdup("/usr/gnu/bin:/usr/local/bin:/bin:/usr/bin:."), \
					1));
	else
	{
		var = ft_var_split(s);
		ft_lstadd_back_env(&lst, ft_lstnew_env(ft_env_strdup(var[0]),
				ft_env_strdup(var[1]), 1));
	}
	return (lst);
}

static t_env	*ft_shlv_var(t_env *lst, char *s)
{
	char	**var;
	int		n;
	char	*aid;

	var = ft_var_split(s);
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
	var = ft_var_split(aid);
	ft_lstadd_back_env(&lst, ft_lstnew_env(ft_env_strdup(var[0]),
			ft_env_strdup(var[1]), 1));
	return (lst);
}

static int	ft_is_in(t_env *lst, char *s)
{
	while (lst)
	{
		if (!ft_strncmp(lst->name, s, INT_MAX))
			return (1);
		lst = lst->next;
	}
	return (0);
}

static t_env	*ft_aid(t_env *lst)
{
	if (!ft_is_in(lst, "PATH"))
		lst = ft_path_var(lst, NULL);
	if (!ft_is_in(lst, "SHLVL"))
		lst = ft_shlv_var(lst, "");
	if (!ft_is_in(lst, "OLDPWD"))
		ft_lstadd_back_env(&lst, ft_lstnew_env(ft_env_strdup("OLDPWD"),
				NULL, 0));
	if (!ft_is_in(lst, "PWD"))
		ft_lstadd_back_env(&lst, ft_lstnew_env(ft_env_strdup("PWD"),
				ft_env_strdup(getcwd(NULL, 0)), 1));
	ft_lstadd_back_env(&lst, ft_lstnew_env(ft_env_strdup("1PWD"),
			ft_env_strdup(getcwd(NULL, 0)), 2));
	return (lst);
}

t_env	*ft_build_env(char **env)
{
	char			**var;
	t_env			*lst;

	lst = NULL;
	while (env && *env)
	{
		var = ft_var_split(*env);
		if (!ft_strncmp(var[0], "PATH", 5))
			lst = ft_path_var(lst, *env);
		else if (!ft_strncmp(var[0], "SHLVL", 6))
			lst = ft_shlv_var(lst, *env);
		else if (!ft_strncmp(var[0], "OLDPWD", 7))
			ft_lstadd_back_env(&lst, ft_lstnew_env(ft_env_strdup("OLDPWD"),
					NULL, 0));
		else if (!ft_strncmp(var[0], "PWD", 4))
			ft_lstadd_back_env(&lst, ft_lstnew_env(ft_env_strdup("PWD"),
					ft_env_strdup(getcwd(NULL, 0)), 1));
		else
			ft_lstadd_back_env(&lst, ft_lstnew_env(ft_env_strdup(var[0]),
					ft_env_strdup(var[1]), !!ft_strchr(*env, '=')));
		env++;
	}
	return (ft_aid(lst));
}
