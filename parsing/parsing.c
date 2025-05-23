/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaliari <amaliari@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-05-23 10:04:19 by amaliari          #+#    #+#             */
/*   Updated: 2025-05-23 10:04:19 by amaliari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

static void	initializing(int *flag, int *flag2)
{
	*flag = 1;
	*flag2 = 0;
}

static void	first_affectation(int *flag2, char **aid)
{
	*aid = NULL;
	*flag2 = 1;
}

static void	second_affectation(t_helper *helper)
{
	helper->var = NULL;
	helper->flag = 0;
}

static void	process_token(char **prompt, t_helper *helper)
{
	while (helper->flag2 && (**prompt == '"' || **prompt == '\''
			|| (!ft_is_space(**prompt) && **prompt)))
	{
		*prompt = ft_parse_quoted_string(*prompt, &(helper->aid));
		second_affectation(helper);
		while (helper->flag2 && !ft_is_space(**prompt) && **prompt
			&& **prompt != '"' && **prompt != '\'')
			*prompt = ft_analyze_next_segment(*prompt, helper);
		if (helper->var)
		{
			helper->aid = ft_expand_split(&(helper->lst), helper->aid,
					helper->var, 1);
			second_affectation(helper);
		}
	}
	if (helper->flag)
		helper->aid = ft_expand_split(&(helper->lst), helper->aid,
				helper->var, 1);
	if (helper->aid)
		ft_lstadd_back_token(&(helper->lst), ft_lstnew_token(helper->aid, 0));
}

t_token	*ft_split_args(char *prompt)
{
	t_helper	helper;

	helper.lst = NULL;
	initializing(&(helper.flag), &(helper.flag2));
	second_affectation(&helper);
	while (prompt && *prompt)
	{
		while (ft_is_space(*prompt))
			prompt++;
		first_affectation(&(helper.flag2), &(helper.aid));
		process_token(&prompt, &helper);
	}
	return (helper.lst);
}
