/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoussas <mhoussas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 17:32:54 by mhoussas          #+#    #+#             */
/*   Updated: 2025/05/23 06:49:29 by mhoussas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

static void	ft_do(char *name)
{
	t_env	*env;
	int		i;

	i = 0;
	env = *ft_env(NULL);
	while (env)
	{
		if (!ft_strncmp(env->name, name, INT_MAX))
		{
			ft_lstdel_in_env(ft_env(NULL), i);
			break ;
		}
		i++;
		env = env->next;
	}
}

int	sh_unset(t_args *args)
{
	char	**lst;
	int		status;

	status = 0;
	lst = args->args;
	while (lst && *lst)
	{
		if (ft_valid_name(*lst))
		{
			if (ft_is_onready(*lst))
				ft_do(*lst);
		}
		else
		{
			ft_print_error("unset", *lst, "not a valid identifier");
			status = 1;
		}
		lst++;
	}
	return (status);
}
