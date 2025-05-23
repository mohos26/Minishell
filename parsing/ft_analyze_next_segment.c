/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_analyze_next_segment.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoussas <mhoussas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 13:08:30 by mhoussas          #+#    #+#             */
/*   Updated: 2025/05/22 13:20:27 by mhoussas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

static void	process_special_help(t_helper *helper)
{
	ft_handle_token(&(helper->lst), &(helper->aid),
		&(helper->var), TOKEN_HEREDOC);
}

static char	*process_special(char *prompt, t_helper *helper)
{
	if (*prompt == '|')
		ft_handle_token(&(helper->lst), &(helper->aid),
			&(helper->var), TOKEN_PIPE);
	else if (*prompt == '<')
	{
		if (*(prompt++ + 1) == '<')
			process_special_help(helper);
		else
			ft_handle_token(&(helper->lst), &(helper->aid),
				&(helper->var), TOKEN_RED_IN);
	}
	else if (*prompt == '>')
	{
		if (*(prompt + 1) == '>')
		{
			ft_handle_token(&(helper->lst), &(helper->aid),
				&(helper->var), TOKEN_RED_APP);
			prompt++;
		}
		else
			ft_handle_token(&(helper->lst), &(helper->aid),
				&(helper->var), TOKEN_RED_OUT);
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
		if (helper->var)
			helper->aid = ft_expand_split(&(helper->lst),
					(helper->aid), (helper->var));
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
