/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handel_token.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoussas <mhoussas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 10:03:37 by amaliari          #+#    #+#             */
/*   Updated: 2025/06/01 10:16:22 by mhoussas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

static char	*ft_aid(int type)
{
	if (type == TOKEN_PIPE)
		return (ft_strdup("|"));
	else if (type == TOKEN_RED_IN)
		return (ft_strdup("<"));
	else if (type == TOKEN_RED_OUT)
		return (ft_strdup(">"));
	else if (type == TOKEN_HEREDOC)
		return (ft_strdup("<<"));
	else if (type == TOKEN_RED_APP)
		return (ft_strdup(">>"));
	return (NULL);
}

void	ft_handle_token(t_helper *helper, int type)
{
	char	*str;

	str = ft_aid(type);
	if (helper->flag)
	{
		helper->aid = ft_expand_split(&(helper->lst), helper->aid,
				helper->var, helper->flag);
		helper->flag = 0;
		helper->flag3 = 1;
	}
	helper->var = NULL;
	if (helper->aid || helper->flag3)
	{
		ft_lstadd_back_token(&(helper->lst), ft_lstnew_token(helper->aid,
				TOKEN_WORD));
		helper->flag3 = 0;
	}
	helper->aid = NULL;
	ft_lstadd_back_token(&(helper->lst), ft_lstnew_token(str, type));
}
