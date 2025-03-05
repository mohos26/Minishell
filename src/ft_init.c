/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoussas <mhoussas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 10:14:11 by mhoussas          #+#    #+#             */
/*   Updated: 2025/03/01 09:05:34 by mhoussas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

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

static void	ft_shlv_utils(char **env)
{
	char	**var;
	int		n;

	var = ft_export_split(*env);
	if (ft_is_number(var[1]))
	{
		n = ft_atoi(var[1]);
		if (n == 999)
			*env = ft_strdup("SHLVL=");
		else
		{
			if (n < 0)
				*env = ft_strdup("SHLVL=0");
			else
				*env = ft_strjoin("SHLVL=", ft_itoa(n + 1));
		}
	}
	else
		*env = ft_strdup("SHLVL=1");
}

static void	ft_shlv(char **env)
{
	char	*s;

	s = ft_strdup("SHLVL=");
	while (env && *env)
	{
		if (!ft_strncmp(s, *env, 6))
		{
			ft_shlv_utils(env);
			break ;
		}
		env++;
	}
}

static char	**ft_check_another_variables(char **env)
{
	if (!ft_is_onready(env, "OLDPWD"))
		env = ft_add_var(env, "OLDPWD");
	if (!ft_is_onready(env, "PWD"))
		env = ft_add_var(env, ft_strdup(ft_strjoin("PWD=", getcwd(NULL, 0))));
	if (!ft_is_onready(env, "PATH"))
		env = ft_add_var(env, ft_strjoin("PATH=/mnt/homes/mhoussas/.docker/bin",
					":/usr/gnu/bin:/usr/local/bin:/bin:/usr/bin:."));
	if (!ft_is_onready(env, "SHLVL"))
		env = ft_add_var(env, ft_strdup("SHLVL=1"));
	else
		ft_shlv(env);
	if (!ft_is_onready(env, "_"))
		env = ft_add_var(env, "_=/usr/bin/env");
	return (env);
}

void	ft_init(char ***enp)
{
	*enp = ft_check_another_variables(*enp);
}
