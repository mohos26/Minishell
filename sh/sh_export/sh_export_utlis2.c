/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_export_utlis2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoussas <mhoussas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 15:31:13 by mhoussas          #+#    #+#             */
/*   Updated: 2025/05/25 16:21:33 by mhoussas         ###   ########.fr       */
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
		if ((!ft_strncmp(env->name, *var, INT_MAX)))
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
	while (var && *var)
	{
		if (*var == '=')
			break ;
		else if (*var == '+')
		{
			if (*++var != '=')
				break ;
			return (1);
		}
		var++;
	}
	return (0);
}

static char	**ft_local_split(char *s)
{
	char	**res;
	int		i;
	int		j;

	i = 0;
	while (s[i] != '+')
		i++;
	res = ft_calloc(sizeof(char *) * 3);
	res[0] = NULL;
	j = 0;
	while (j < i)
		res[0] = ft_append_str(res[0], s[j++]);
	res[1] = ft_strchr(s, '=') + 1;
	res[2] = NULL;
	return (res);
}

int	ft_append(char *var)
{
	char	**lst;
	int		status;

	status = 0;
	lst = ft_local_split(var);
	if (ft_valid_name(*lst))
	{
		if (ft_is_onready(*lst))
			ft_append_env_value(lst);
		else
			ft_add_var(lst);
	}
	else
	{
		ft_print_error("export", var, "not a valid identifier");
		status = 1;
	}
	return (status);
}
