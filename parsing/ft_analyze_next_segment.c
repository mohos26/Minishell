/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_analyze_next_segment.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoussas <mhoussas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 10:03:28 by amaliari          #+#    #+#             */
/*   Updated: 2025/06/01 16:38:33 by mhoussas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

static char	*process_special(char *prompt, t_helper *helper)
{
	if (*prompt == '|')
		ft_handle_token(helper, TOKEN_PIPE);
	else if (*prompt == '<')
	{
		if (*(prompt + 1) == '<')
		{
			ft_handle_token(helper, TOKEN_HEREDOC);
			prompt++;
		}
		else
			ft_handle_token(helper, TOKEN_RED_IN);
	}
	else if (*prompt == '>')
	{
		if (*(prompt + 1) == '>')
		{
			ft_handle_token(helper, TOKEN_RED_APP);
			prompt++;
		}
		else
			ft_handle_token(helper, TOKEN_RED_OUT);
	}
	helper->flag2 = 0;
	return (prompt + 1);
}

static char	*process_char(char *prompt, t_helper *helper)
{
	if (*prompt == '$' && !helper->flag)
		helper->flag = 1;
	else if (helper->flag && ft_is_valid((helper->var), *prompt))
		helper->var = ft_append_str((helper->var), *prompt);
	else if (helper->flag)
	{
		helper->aid = ft_expand_split(&(helper->lst),
				(helper->aid), (helper->var), 1);
		prompt--;
		helper->flag = 0;
		(helper->var) = NULL;
	}
	else
		(helper->aid) = ft_append_str((helper->aid), *prompt);
	return (prompt + 1);
}

char	*ft_analyze_next_segment(char *prompt, t_helper *helper)
{
	if (*prompt == '|' || *prompt == '<' || *prompt == '>')
		return (process_special(prompt, helper));
	return (process_char(prompt, helper));
}
