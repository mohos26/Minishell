/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoussas <mhoussas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 17:32:54 by mhoussas          #+#    #+#             */
/*   Updated: 2025/04/15 12:19:54 by mhoussas         ###   ########.fr       */
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
		if (!ft_strncmp(env->name, name, ft_strlen(name) + 1))
		{
			ft_lstdel_in_env(ft_env(NULL), i);
			break ;
		}
		i++;
		env = env->next;
	}
}

void	sh_unset(t_args *args)
{
	char	**lst;

	lst = args->args;
	while (lst && *lst)
	{
		if (ft_valid_name(*lst))
		{
			if (ft_is_onready(*lst))
				ft_do(*lst);
		}
		else
			ft_print_error("unset", *lst, "not a valid identifier");
		lst++;
	}
}
