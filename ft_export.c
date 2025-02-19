/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoussas <mhoussas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 18:42:43 by mhoussas          #+#    #+#             */
/*   Updated: 2025/02/19 21:40:57 by mhoussas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static char	**ft_sort(char **lst)
{

}

void	ft_export(char **args, char **env)
{
	if (!args || !*args)
	{
		env = ft_sort(env);
		while (env && *env)
		{
			if (ft_strncmp(*env, "_=", 2))
				printf("declare -x %s\n", *env);
			env++;
		}
		return ;
	}

}
