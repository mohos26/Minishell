/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoussas <mhoussas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 18:42:43 by mhoussas          #+#    #+#             */
/*   Updated: 2025/05/25 16:22:51 by mhoussas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

static void	ft_print_env(void)
{
	char	**env;
	char	*res;
	char	**aid;
	char	*aid2;

	res = NULL;
	env = ft_sort();
	while (env && *env)
	{
		aid = ft_var_split(*env);
		aid2 = *aid;
		if (ft_strchr(*env, '='))
			aid2 = ft_strjoin(aid[0], ft_strjoin("=", ft_strjoin("\"",
							ft_strjoin(aid[1], "\""))));
		res = ft_strjoin(ft_strjoin(res, ft_strjoin("declare -x ", aid2)),
				"\n");
		env++;
	}
	ft_putstr_fd(res, 1);
}

static void	ft_add_var(char *var)
{
	char	**res;

	res = ft_var_split(var);
	ft_lstadd_back_env(ft_env(NULL), ft_lstnew_env(ft_env_strdup(res[0]),
			ft_env_strdup(res[1]), !!ft_strchr(var, '=')));
}

static void	ft_reset_var(char *s)
{
	char	**var;
	t_env	*env;

	if (!ft_strchr(s, '='))
		return ;
	env = *ft_env(NULL);
	var = ft_var_split(s);
	while (env)
	{
		if (!ft_strncmp(env->name, *var, INT_MAX))
		{
			free(env->value);
			env->value = ft_env_strdup(var[1]);
			env->active = 1;
			break ;
		}
		env = env->next;
	}
}

static void	ft_aid(char *var, char *lst)
{
	if (ft_is_onready(var))
		ft_reset_var(lst);
	else
		ft_add_var(lst);
}

int	sh_export(t_args *args)
{
	int		status;
	char	**var;
	char	**lst;

	status = 0;
	lst = args->args;
	if (!lst || !*lst)
		ft_print_env();
	while (lst && *lst)
	{
		if (ft_is_append(*lst))
			return (ft_append(*lst));
		var = ft_var_split(*lst);
		if (ft_valid_name(*var))
			ft_aid(*var, *lst);
		else
		{
			status = 1;
			ft_print_error("export", *lst, "not a valid identifier");
		}
		lst++;
	}
	return (status);
}
