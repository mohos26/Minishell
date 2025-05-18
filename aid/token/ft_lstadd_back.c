/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoussas <mhoussas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 16:00:15 by mhoussas          #+#    #+#             */
/*   Updated: 2025/05/16 09:48:31 by mhoussas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

void	ft_lstadd_back_token(t_token **lst, t_token *new)
{
	t_token	*aid;

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
