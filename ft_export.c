/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoussas <mhoussas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 18:42:43 by mhoussas          #+#    #+#             */
/*   Updated: 2025/02/21 19:32:35 by mhoussas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int	ft_valid_name(char *s)
{
	if (!ft_isalpha(*s) && *s != '_')
		return (0);
	s++;
	while (*s)
	{
		if (!ft_isalnum(*s) && *s != '_')
			return (0);
		s++;
	}
	return (1);
}

static int	ft_is_onready(char **env, char *name)
{
	name = ft_strjoin(name, "=");
	while (*env)
	{
		if (!ft_strncmp(*env, name, ft_strlen(name))
			|| !ft_strncmp(*env, name, ft_strlen(*env)))
			return (1);
		env++;
	}
	return (0);
}

void	ft_reset_var(char **env, char *s)
{
	char	*name;

	name = ft_strjoin(*ft_export_split(s), "=");
	while (*env)
	{
		if (!ft_strncmp(*env, name, ft_strlen(name))
			|| !ft_strncmp(*env, name, ft_strlen(*env)))
			*env = ft_strdup(s);
		env++;
	}
}

void	ft_export(char **args, char ***enp)
{
	char	**var;
	char	**env;

	env = *enp;
	if (!args || !*args)
	{
		ft_print_env(env);
	}
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
		args++;
	}
}
