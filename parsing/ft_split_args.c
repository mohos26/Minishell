/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoussas <mhoussas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 10:04:19 by amaliari          #+#    #+#             */
/*   Updated: 2025/06/15 12:14:37 by mhoussas         ###   ########.fr       */
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

static void	process_token(char **prompt, t_helper *help)
{
	help->flag3 = 0;
	while (help->flag2 && (**prompt == '"' || **prompt == '\''
			|| (!ft_is_space(**prompt) && **prompt)))
	{
		*prompt = ft_parse_quoted_string(*prompt, &(help->aid));
		second_affectation(help);
		while (help->flag2 && !ft_is_space(**prompt) && **prompt
			&& **prompt != '"' && **prompt != '\'')
			*prompt = ft_analyze_next_segment(*prompt, help);
		if (help->var)
		{
			help->aid = ft_expand_split(&(help->lst), help->aid,
					help->var, 1);
			second_affectation(help);
			help->flag3 = 1;
		}
	}
	if (help->flag)
		help->aid = ft_expand_split(&(help->lst), help->aid,
				help->var, 1);
	if (help->aid || help->flag3)
	{
		ft_lstadd_back_token(&(help->lst), ft_lstnew_token(help->aid, 0, 0));
		help->flag3 = 0;
	}
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
