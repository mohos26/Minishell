/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoussas <mhoussas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 16:00:15 by mhoussas          #+#    #+#             */
/*   Updated: 2025/04/15 16:29:38 by mhoussas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

void	ft_lstadd_back_red(t_red **lst, t_red *new)
{
	t_red	*aid;

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
