/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_update_status.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoussas <mhoussas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 17:54:26 by mhoussas          #+#    #+#             */
/*   Updated: 2025/06/14 11:49:52 by mhoussas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	ft_update_status(int status)
{
	t_env	*env;

	env = *ft_env(NULL);
	while (env)
	{
		if (!ft_strncmp(env->name, "?", INT_MAX))
			break ;
		env = env->next;
	}
	free(env->value);
	env->value = ft_env_strdup(ft_itoa(status));
}
