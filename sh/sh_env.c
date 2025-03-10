/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoussas <mhoussas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 19:21:52 by mhoussas          #+#    #+#             */
/*   Updated: 2025/03/10 09:36:45 by mhoussas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	sh_env(void)
{
	t_list	*env;

	env = *ft_getenv(NULL);
	while (env)
	{
		if (env->active)
		{
			printf("%s=", env->name);
			if (env->value)
				printf("%s", env->value);
			printf("\n");
		}
		env = env->next;
	}
}
