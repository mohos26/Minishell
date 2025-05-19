/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_syntax_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoussas <mhoussas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 21:47:16 by mhoussas          #+#    #+#             */
/*   Updated: 2025/05/19 21:54:10 by mhoussas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

static int	ft_aid(t_token *token)
{
	if (token->type == TOKEN_RED_IN || token->type == TOKEN_RED_APP
		|| token->type == TOKEN_RED_OUT || token->type == TOKEN_HEREDOC)
		return (!token->next || token->next->type != TOKEN_WORD);
	if (token->type == TOKEN_PIPE)
		return (!token->next || token->next->type == TOKEN_PIPE);
	return (0);
}

static int	ft_syntax_exit(void)
{
	ft_print_error("syntax", "syntax error near unexpected token", "Nothing");
	return (258);
}

int	ft_syntax_error(t_token *tokens)
{
	t_token	*temp;

	temp = tokens;
	if (temp && temp->type == TOKEN_PIPE)
		return (ft_syntax_exit());
	while (temp)
	{
		if (ft_aid(temp))
			return (ft_syntax_exit());
		temp = temp->next;
	}
	if (tokens && ft_lstlast_token(tokens)->type != TOKEN_WORD)
		return (ft_syntax_exit());
	return (0);
}
