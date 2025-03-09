/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoussas <mhoussas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 16:00:15 by mhoussas          #+#    #+#             */
/*   Updated: 2025/03/09 12:21:32 by mhoussas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*aid;

	if (!lst || !new)
		return ;
	if (!*lst)
		*lst = new;
	else
	{
		aid = *lst;
		while (aid->next)
			aid = aid->next;
		aid->next = new;
	}
}
