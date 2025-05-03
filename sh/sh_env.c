/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoussas <mhoussas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 19:21:52 by mhoussas          #+#    #+#             */
/*   Updated: 2025/05/03 15:04:48 by mhoussas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	sh_env(void)
{
	t_env	*env;

	env = *ft_env(NULL);
	while (env)
	{
		if (env->active == 1)
		{
			ft_putstr_fd(ft_strjoin(env->name, "="), 1);
			if (env->value)
				ft_putstr_fd(env->value, 1);
			ft_putstr_fd("\n", 1);
		}
		env = env->next;
	}
}
