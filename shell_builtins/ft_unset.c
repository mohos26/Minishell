/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoussas <mhoussas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 17:32:54 by mhoussas          #+#    #+#             */
/*   Updated: 2025/02/22 19:08:36 by mhoussas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

char	**ft_do(char **env, char *name)
{
	char	**res;
	char	**aid;
	int		len;

	len = 0;
	while (env[len])
		len++;
	res = malloc((len - 1) * sizeof(char *) + 1);
	aid = res;
	while (*env)
	{
		if (ft_strncmp(*env, name, ft_strlen(name))
			&& ft_strncmp(*env, name, ft_strlen(*env)))
			*aid++ = ft_strdup(*env);
		env++;
	}
	*aid = NULL;
	return (res);
}

void	ft_unset(char **args, char ***enp)
{
	while (args && *args)
	{
		if (ft_valid_name(*args))
		{
			if (ft_is_onready(*enp, *args))
				*enp = ft_do(*enp, *args);
		}
		else
			ft_print_error("unset", *args, "not a valid identifier");
		args++;
	}
}
