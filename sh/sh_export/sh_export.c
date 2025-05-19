/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoussas <mhoussas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 18:42:43 by mhoussas          #+#    #+#             */
/*   Updated: 2025/05/19 09:47:49 by mhoussas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

static char	**ft_sort(void)
{
	char	**lst;
	char	*tmp;
	int		i;
	int		j;

	i = 0;
	lst = ft_convert_env();
	while (lst && *lst && lst[i + 1])
	{
		j = i + 1;
		while (lst[j])
		{
			if (ft_strncmp(lst[i], lst[j], INT_MAX) > 0)
			{
				tmp = lst[i];
				lst[i] = lst[j];
				lst[j] = tmp;
			}
			j++;
		}
		i++;
	}
	return (lst);
}

static void	ft_print_env(void)
{
	char	**env;
	char	*res;

	res = NULL;
	env = ft_sort();
	while (env && *env)
	{
		res = ft_strjoin(ft_strjoin(res, \
				ft_strjoin("declare -x ", ft_strjoin("\"", ft_strjoin(*env,
								"\"")))), "\n");
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

	env = *ft_env(NULL);
	var = ft_var_split(s);
	while (**(var + 1) && env)
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

void	sh_export(t_args *args)
{
	char	**var;
	char	**lst;

	lst = args->args;
	if (!lst || !*lst)
		ft_print_env();
	while (lst && *lst)
	{
		if (ft_is_append(*lst))
			return (ft_append(*lst));
		var = ft_var_split(*lst);
		if (ft_valid_name(*var))
		{
			if (ft_is_onready(*var))
				ft_reset_var(*lst);
			else
				ft_add_var(*lst);
		}
		else
			ft_print_error("export", *lst, "not a valid identifier");
		lst++;
	}
}
