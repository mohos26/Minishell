/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoussas <mhoussas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 18:42:43 by mhoussas          #+#    #+#             */
/*   Updated: 2025/02/20 21:44:35 by mhoussas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static char	**ft_sort(char **lst)
{
	int	len;
	int	i;
	int	j;
	char *tmp;

	len = 0;
	while (lst[len])
		len++;
	i = 0;
	while (lst[i+1])
	{
		j = i + 1;
		while (lst[j])
		{
			if (ft_strncmp(lst[i], lst[j], INT_MAX) > 0)
			{
				tmp = lst[i];
				lst[i] = lst[j];
				lst[j] = tmp;
			}
			j++;
		}
		i++;
	}
	return (lst);
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
