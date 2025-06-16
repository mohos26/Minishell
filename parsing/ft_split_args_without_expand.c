/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_args_without_expand.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoussas <mhoussas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 13:37:34 by mhoussas          #+#    #+#             */
/*   Updated: 2025/06/15 12:13:20 by mhoussas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

static void	ft_aid3(t_helper *helper, int type)
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
	if (helper->aid)
		ft_lstadd_back_token(&(helper->lst), ft_lstnew_token(helper->aid,
				TOKEN_WORD, 0));
	helper->aid = NULL;
	ft_lstadd_back_token(&(helper->lst), ft_lstnew_token(str, type, 0));
}

static char	*process_special(char *prompt, t_helper *helper)
{
	if (*prompt == '|')
		ft_aid3(helper, TOKEN_PIPE);
	else if (*prompt == '<')
	{
		if (*(prompt + 1) == '<')
		{
			ft_aid3(helper, TOKEN_HEREDOC);
			prompt++;
		}
		else
			ft_aid3(helper, TOKEN_RED_IN);
	}
	else if (*prompt == '>')
	{
		if (*(prompt + 1) == '>')
		{
			ft_aid3(helper, TOKEN_RED_APP);
			prompt++;
		}
		else
			ft_aid3(helper, TOKEN_RED_OUT);
	}
	return (prompt + 1);
}

static char	*ft_aid(char *prompt, char **aid, int *flag)
{
	char	*var;

	var = NULL;
	if (*prompt == '"')
		prompt++;
	else if (*prompt == '\'')
	{
		while (*++prompt != '\'' && *prompt)
			*aid = ft_append_str(*aid, *prompt);
	}
	if ((*prompt == '"' || *prompt == '\'') && !*aid)
		*aid = ft_strdup("");
	if (*prompt == '"' || *prompt == '\'')
	{
		prompt++;
		*flag = 1;
	}
	return (prompt);
}

static void	process_token(char **prompt, t_helper *helper)
{
	int	flag;

	flag = 0;
	while ((**prompt == '"' || **prompt == '\''
			|| (!ft_is_space(**prompt) && **prompt)))
	{
		*prompt = ft_aid(*prompt, &(helper->aid), &flag);
		while (!ft_is_space(**prompt) && **prompt
			&& **prompt != '"' && **prompt != '\'')
		{
			if (**prompt == '|' || **prompt == '<' || **prompt == '>')
				*prompt = process_special(*prompt, helper);
			else
				helper->aid = ft_append_str(helper->aid, *(*prompt)++);
		}
	}
	if (helper->aid)
		ft_lstadd_back_token(&(helper->lst), ft_lstnew_token(helper->aid, 0,
				flag));
}

t_token	*ft_split_args_without_expand(char *prompt)
{
	t_helper	helper;

	helper.lst = NULL;
	while (prompt && *prompt)
	{
		while (ft_is_space(*prompt))
			prompt++;
		helper.aid = NULL;
		process_token(&prompt, &helper);
	}
	return (helper.lst);
}
