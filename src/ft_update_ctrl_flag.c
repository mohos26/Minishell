/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_update_ctrl_flag.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoussas <mhoussas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 18:09:20 by mhoussas          #+#    #+#             */
/*   Updated: 2025/05/25 18:14:07 by mhoussas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_update_ctrl_flag(int flag)
{
	t_env	*env;

	env = *ft_env(NULL);
	while (env)
	{
		if (!ft_strncmp(env->name, "1ctrl", INT_MAX))
			break ;
		env = env->next;
	}
	free(env->value);
	env->value = ft_env_strdup(ft_itoa(flag));
}
