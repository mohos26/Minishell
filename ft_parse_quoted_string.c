/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_quoted_string.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaliari <amaliari@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-05-23 10:03:42 by amaliari          #+#    #+#             */
/*   Updated: 2025-05-23 10:03:42 by amaliari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

static void	ft_handle_dollar_quote(char **aid, char **var,
			int *flag, char **prompt)
{
	if (**prompt == '$' && !*flag)
		*flag = 1;
	else if (*flag && ft_is_valid(*var, **prompt))
		*var = ft_append_str(*var, **prompt);
	else if (*flag)
	{
		*aid = ft_strjoin(*aid, ft_expand_quotes(*var));
		*flag = 0;
		*var = NULL;
		(*prompt)--;
	}
	else
		*aid = ft_append_str(*aid, **prompt);
}

char	*ft_parse_quoted_string(char *prompt, char **aid)
{
	char	*var;
	int		flag;

	var = NULL;
	flag = 0;
	if (*prompt == '"')
	{
		while (*++prompt != '"' && *prompt)
			ft_handle_dollar_quote(aid, &var, &flag, &prompt);
		if (flag)
		{
			flag = 0;
			*aid = ft_strjoin(*aid, ft_expand_quotes(var));
		}
	}
	else if (*prompt == '\'')
	{
		while (*++prompt != '\'' && *prompt)
			*aid = ft_append_str(*aid, *prompt);
	}
	if ((*prompt == '"' || *prompt == '\'') && !*aid)
		*aid = ft_strdup("");
	if (*prompt == '"' || *prompt == '\'')
		prompt++;
	return (prompt);
}
