/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_here_doc_limiters.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoussas <mhoussas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 20:21:29 by mhoussas          #+#    #+#             */
/*   Updated: 2025/06/03 21:51:55 by mhoussas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

static char	*ft_aid(t_token *lst)
{
	while (lst)
	{
		if (lst->type == TOKEN_HEREDOC)
		{
			lst->type = TOKEN_WORD;
			return (lst->next->value);
		}
		lst = lst->next;
	}
	return (NULL);
}

t_token	*ft_here_doc_limiters(t_token *base_lst, t_token *lst_no_expand)
{
	t_token	*header;

	header = base_lst;
	while (base_lst)
	{
		if (base_lst->type == TOKEN_HEREDOC)
		{
			base_lst = base_lst->next;
			base_lst->value = ft_aid(lst_no_expand);
		}
		base_lst = base_lst->next;
	}
	return (header);
}
