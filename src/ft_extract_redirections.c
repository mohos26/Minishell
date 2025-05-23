/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extract_redirections.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoussas <mhoussas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 16:37:46 by mhoussas          #+#    #+#             */
/*   Updated: 2025/05/21 16:46:53 by mhoussas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

static int	ft_aid(t_token **lst, t_red **res, int *flag)
{
	char	*aid;

	*lst = (*lst)->next;
	aid = ft_here_doc((*lst)->value);
	if (!aid)
	{
		*flag = 1;
		return (1);
	}
	ft_lstadd_back_red(res, ft_lstnew_red(aid, 1, 1));
	return (0);
}

t_red	*ft_extract_redirections(t_token *lst, int *flag)
{
	t_red	*res;
	int		type;

	res = NULL;
	while (lst)
	{
		if (lst->type == TOKEN_PIPE)
			break ;
		else if (lst->type == TOKEN_RED_IN || lst->type == TOKEN_RED_OUT
			|| lst->type == TOKEN_RED_APP)
		{
			type = lst->type - 1;
			lst = lst->next;
			ft_lstadd_back_red(&res, ft_lstnew_red(lst->value, type, 0));
		}
		else if (lst->type == TOKEN_HEREDOC)
			if (ft_aid(&lst, &res, flag))
				return (NULL);
		lst = lst->next;
	}
	return (res);
}
