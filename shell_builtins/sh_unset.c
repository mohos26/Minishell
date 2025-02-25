/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoussas <mhoussas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 17:32:54 by mhoussas          #+#    #+#             */
/*   Updated: 2025/02/25 10:19:36 by mhoussas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

char	**ft_do(char **env, char *name)
{
	char	**res;
	char	**aid;
	int		len;

	len = 0;
	while (env && env[len])
		len++;
	res = ft_calloc((len - 1) * sizeof(char *) + 1);
	aid = res;
	while (env && *env)
	{
		if (ft_strncmp(*env, name, ft_strlen(name))
			&& ft_strncmp(*env, name, ft_strlen(*env)))
			*aid++ = ft_strdup(*env);
		env++;
	}
	*aid = NULL;
	return (res);
}

void	sh_unset(t_args *args)
{
	char	**lst;

	lst = args->args;
	while (lst && *lst)
	{
		if (ft_valid_name(*lst))
		{
			if (ft_is_onready(*(args->env), *lst))
				*(args->env) = ft_do(*(args->env), *lst);
		}
		else
			ft_print_error("unset", *lst, "not a valid identifier");
		lst++;
	}
}
