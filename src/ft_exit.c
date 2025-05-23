/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoussas <mhoussas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 18:35:55 by mhoussas          #+#    #+#             */
/*   Updated: 2025/05/22 18:36:09 by mhoussas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	ft_exit(int status)
{
	t_env	*lst;
	t_env	*tmp;

	ft_clean();
	rl_clear_history();
	lst = *ft_env(NULL);
	while (lst)
	{
		tmp = lst;
		free(lst->name);
		free(lst->value);
		lst = lst->next;
		free(tmp);
	}
	exit(status);
}
