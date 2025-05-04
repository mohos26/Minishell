/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoussas <mhoussas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 19:21:52 by mhoussas          #+#    #+#             */
/*   Updated: 2025/05/04 19:19:38 by mhoussas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	sh_env(void)
{
	t_env	*env;
	char	*res;

	res = NULL;
	env = *ft_env(NULL);
	while (env)
	{
		if (env->active == 1)
		{
			res = ft_strjoin(res, ft_strjoin(env->name, "="));
			if (env->value)
				res = ft_strjoin(res, env->value);
			res = ft_strjoin(res, "\n");
		}
		env = env->next;
	}
	ft_putstr_fd(res, 1);
}
