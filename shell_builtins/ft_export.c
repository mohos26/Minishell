/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoussas <mhoussas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 18:42:43 by mhoussas          #+#    #+#             */
/*   Updated: 2025/02/23 11:27:53 by mhoussas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

static char	**ft_sort(char **lst)
{
	char	*tmp;
	int		len;
	int		i;
	int		j;

	len = 0;
	while (lst && lst[len])
		len++;
	i = 0;
	while (lst && lst[i + 1])
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
			printf("declare -x %s=\"%s\"\n", var[0], var[1]);
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

void	sh_export(char **args, char ***enp)
{
	char	**var;
	char	**env;

	env = *enp;
	if (!args || !*args)
		ft_print_env(env);
	while (args && *args)
	{
		var = ft_export_split(*args);
		if (ft_valid_name(*var))
		{
			if (ft_is_onready(env, *var))
				ft_reset_var(env, *args);
			else
				*enp = ft_add_var(env, *args);
			env = *enp;
		}
		else
			ft_print_error("export", *args, "not a valid identifier");
		args++;
	}
}
