/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handel_token.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaliari <amaliari@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-05-23 10:03:37 by amaliari          #+#    #+#             */
/*   Updated: 2025-05-23 10:03:37 by amaliari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	ft_handle_token(t_helper *t_helper, int type)
{
	char	*str;

	str = NULL;
	if (type == TOKEN_PIPE)
		str = ft_strdup("|");
	else if (type == TOKEN_RED_IN)
		str = ft_strdup("<");
	else if (type == TOKEN_RED_OUT)
		str = ft_strdup(">");
	else if (type == TOKEN_HEREDOC)
		str = ft_strdup("<<");
	else if (type == TOKEN_RED_APP)
		str = ft_strdup(">>");
	if (t_helper->flag)
	{
		t_helper->aid = ft_expand_split(&(t_helper->lst), t_helper->aid,
				t_helper->var, 0);
		t_helper->flag = 0;
	}
	t_helper->var = NULL;
	if (t_helper->aid)
		ft_lstadd_back_token(&(t_helper->lst), ft_lstnew_token(t_helper->aid,
				TOKEN_WORD));
	t_helper->aid = NULL;
	ft_lstadd_back_token(&(t_helper->lst), ft_lstnew_token(str, type));
}
