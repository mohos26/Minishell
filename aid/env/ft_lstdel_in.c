/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel_in.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoussas <mhoussas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 08:50:46 by mhoussas          #+#    #+#             */
/*   Updated: 2025/04/15 11:39:35 by mhoussas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

void	ft_lstdel_in_env(t_env **lst, int i)
{
	t_env	*aid;
	int		j;

	if (!lst || !*lst)
		return ;
	aid = *lst;
	j = 0;
	while (i && j != (i - 1))
	{
		aid = aid->next;
		j++;
	}
	if (!i)
		*lst = aid->next;
	else
		aid->next = aid->next->next;
}
