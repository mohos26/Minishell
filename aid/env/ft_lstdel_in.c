/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel_in.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoussas <mhoussas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 08:50:46 by mhoussas          #+#    #+#             */
/*   Updated: 2025/05/23 21:43:07 by mhoussas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

static void	ft_local_free(t_env *node)
{
	if (!node)
		return ;
	free(node->name);
	free(node->value);
	free(node);
}

void	ft_lstdel_in_env(t_env **lst, int i)
{
	t_env	*aid;
	t_env	*tmp;
	int		j;

	if (!lst || !*lst)
		return ;
	j = 0;
	aid = *lst;
	while (i && j != (i - 1))
	{
		aid = aid->next;
		j++;
	}
	if (!i)
	{
		tmp = *lst;
		*lst = aid->next;
		ft_local_free(tmp);
	}
	else
	{
		tmp = aid->next;
		aid->next = aid->next->next;
		ft_local_free(tmp);
	}
}
