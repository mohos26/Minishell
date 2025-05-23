/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_env.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoussas <mhoussas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 18:18:27 by mhoussas          #+#    #+#             */
/*   Updated: 2025/05/22 18:18:52 by mhoussas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

char	**ft_convert_env(void)
{
	char	**head;
	char	*node;
	char	**res;
	t_env	*env;

	env = *ft_env(NULL);
	res = ft_calloc((ft_lstsize_env(env) + 1) * sizeof(char *));
	head = res;
	while (env)
	{
		if (env->active == 2)
		{
			env = env->next;
			continue ;
		}
		node = env->name;
		if (env->active)
			node = ft_strjoin(ft_strjoin(node, "="), env->value);
		*res++ = node;
		env = env->next;
	}
	*res = NULL;
	return (head);
}
