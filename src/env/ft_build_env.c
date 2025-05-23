/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_build_env.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoussas <mhoussas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 12:03:27 by mhoussas          #+#    #+#             */
/*   Updated: 2025/05/20 18:37:49 by mhoussas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

static t_env	*ft_path_var(t_env *lst, char *s)
{
	char	**key_value_pair;

	if (!s)
		ft_lstadd_back_env(&lst, ft_lstnew_env(ft_env_strdup("PATH"),
				ft_env_strdup("/usr/gnu/bin:/usr/local/bin:/bin:/usr/bin:."), \
					1));
	else
	{
		key_value_pair = ft_var_split(s);
		ft_lstadd_back_env(&lst, ft_lstnew_env(ft_env_strdup(key_value_pair[0]),
				ft_env_strdup(key_value_pair[1]), 1));
	}
	return (lst);
}

static t_env	*ft_shlv_var(t_env *lst, char *s)
{
	char	**shlvl_kv;
	char	*shlvl_str;
	int		n;

	shlvl_kv = ft_var_split(s);
	if (ft_is_number(shlvl_kv[1]))
	{
		n = ft_atoi(shlvl_kv[1]);
		if (n == 999)
			shlvl_str = ft_strdup("SHLVL=");
		else
		{
			if (n < 0)
				shlvl_str = ft_strdup("SHLVL=0");
			else
				shlvl_str = ft_strjoin("SHLVL=", ft_itoa(n + 1));
		}
	}
	else
		shlvl_str = ft_strdup("SHLVL=1");
	shlvl_kv = ft_var_split(shlvl_str);
	ft_lstadd_back_env(&lst, ft_lstnew_env(ft_env_strdup(shlvl_kv[0]),
			ft_env_strdup(shlvl_kv[1]), 1));
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

static t_env	*ft_ensure_default_env_vars(t_env *lst)
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
				ft_env_strdup(ft_getcwd(NULL, 0)), 1));
	ft_lstadd_back_env(&lst, ft_lstnew_env(ft_env_strdup("1PWD"),
			ft_env_strdup(ft_getcwd(NULL, 0)), 2));
	ft_lstadd_back_env(&lst, ft_lstnew_env(ft_env_strdup("?"),
			ft_env_strdup("0"), 2));
	return (lst);
}

t_env	*ft_build_env(char **env)
{
	char			**env_kv_pair;
	t_env			*lst;

	lst = NULL;
	while (env && *env)
	{
		env_kv_pair = ft_var_split(*env);
		if (!ft_strncmp(env_kv_pair[0], "PATH", INT_MAX))
			lst = ft_path_var(lst, *env);
		else if (!ft_strncmp(env_kv_pair[0], "SHLVL", INT_MAX))
			lst = ft_shlv_var(lst, *env);
		else if (!ft_strncmp(env_kv_pair[0], "OLDPWD", INT_MAX))
			ft_lstadd_back_env(&lst, ft_lstnew_env(ft_env_strdup("OLDPWD"),
					NULL, 0));
		else if (!ft_strncmp(env_kv_pair[0], "PWD", INT_MAX))
			ft_lstadd_back_env(&lst, ft_lstnew_env(ft_env_strdup("PWD"),
					ft_env_strdup(ft_getcwd(NULL, 0)), 1));
		else
			ft_lstadd_back_env(&lst, ft_lstnew_env(ft_env_strdup(*env_kv_pair),
					ft_env_strdup(env_kv_pair[1]), !!ft_strchr(*env, '=')));
		env++;
	}
	return (ft_ensure_default_env_vars(lst));
}
