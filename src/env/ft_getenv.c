/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoussas <mhoussas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 15:36:53 by mhoussas          #+#    #+#             */
/*   Updated: 2025/04/12 15:40:34 by mhoussas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

char	*ft_getenv(char *name)
{
	t_list	*env;

	env = *ft_env(NULL);
	while (env)
	{
		if (!ft_strncmp(env->name, name, INT_MAX))
			return (env->value);
		env = env->next;
	}
	return (NULL);
}
