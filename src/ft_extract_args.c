/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extract_args.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoussas <mhoussas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 16:35:53 by mhoussas          #+#    #+#             */
/*   Updated: 2025/05/21 16:46:32 by mhoussas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

static char	**ft_append_array(char **lst, char *s)
{
	char	**res;
	int		len;

	len = 0;
	while (lst && lst[len])
		len++;
	res = ft_calloc((len + 2) * sizeof(char *));
	len = 0;
	while (lst && lst[len])
	{
		res[len] = lst[len];
		len++;
	}
	res[len] = s;
	res[len + 1] = NULL;
	return (res);
}

char	**ft_extract_args(t_token *lst)
{
	char	**res;
	int		flag;

	flag = 0;
	res = NULL;
	while (lst)
	{
		if (lst->type == TOKEN_PIPE)
			break ;
		else if (lst->type == TOKEN_WORD && flag)
			res = ft_append_array(res, lst->value);
		else if (lst->type == TOKEN_WORD)
			flag = 1;
		else if (lst->type == TOKEN_RED_IN || lst->type == TOKEN_RED_OUT
			|| lst->type == TOKEN_RED_APP || lst->type == TOKEN_HEREDOC)
			lst = lst->next;
		if (lst)
			lst = lst->next;
	}
	return (res);
}
