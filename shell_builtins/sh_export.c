/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoussas <mhoussas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 18:42:43 by mhoussas          #+#    #+#             */
/*   Updated: 2025/02/25 10:19:29 by mhoussas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

static char	**ft_sort(char **lst)
{
	char	*tmp;
	int		i;
	int		j;

	i = 0;
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

static void	ft_print_env(char **env)
{
	char	**var;

	env = ft_sort(env);
	while (env && *env)
	{
		var = ft_export_split(*env);
		if (ft_strncmp(*var, "_", 2))
		{
			printf("declare -x ");
			if (ft_strchr(*env, '='))
				printf("%s=\"%s\"\n", var[0], var[1]);
			else
				printf("%s\n", *env);
		}
		env++;
	}
}

void	ft_reset_var(char **env, char *s)
{
	char	**var;

	var = ft_export_split(s);
	*var = ft_strjoin(*ft_export_split(s), "=");
	while (**(var + 1) && env && *env)
	{
		if (!ft_strncmp(*env, *var, ft_strlen(*var))
			|| !ft_strncmp(*env, *var, ft_strlen(*env)))
			*env = ft_strdup(s);
		env++;
	}
}

void	sh_export(t_args *args)
{
	char	**var;
	char	**env;
	char	**lst;

	lst = args->args;
	env = *(args->env);
	if (!lst || !*lst)
		ft_print_env(env);
	while (lst && *lst)
	{
		var = ft_export_split(*lst);
		if (ft_valid_name(*var))
		{
			if (ft_is_onready(env, *var))
				ft_reset_var(env, *lst);
			else
				*(args->env) = ft_add_var(env, *lst);
			env = *(args->env);
		}
		else
			ft_print_error("export", *lst, "not a valid identifier");
		lst++;
	}
}
