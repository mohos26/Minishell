/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_export_utlis2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoussas <mhoussas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 15:31:13 by mhoussas          #+#    #+#             */
/*   Updated: 2025/04/15 14:19:24 by mhoussas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

static void	ft_append_env_value(char **var)
{
	t_env	*env;
	char	*tmp;

	env = *ft_env(NULL);
	while (**(var + 1) && env)
	{
		if ((!ft_strncmp(env->name, *var, ft_strlen(*var) + 1)))
		{
			tmp = env->value;
			env->value = ft_env_strdup(ft_strjoin(tmp, var[1]));
			env->active = 1;
			free(tmp);
			break ;
		}
		env = env->next;
	}
}

static void	ft_add_var(char **var)
{
	ft_lstadd_back_env(ft_env(NULL), ft_lstnew_env(ft_env_strdup(var[0]),
			ft_env_strdup(var[1]), 1));
}

int	ft_is_append(char *var)
{
	return (!!ft_strnstr(var, "+=", INT_MAX));
}

void	ft_append(char *var)
{
	char	**lst;

	lst = ft_split(var, '+');
	(*(lst + 1))++;
	if (ft_valid_name(*lst))
	{
		if (ft_is_onready(*lst))
			ft_append_env_value(lst);
		else
			ft_add_var(lst);
	}
	else
		ft_print_error("export", var, "not a valid identifier");
}
