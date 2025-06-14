/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extract_command.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoussas <mhoussas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 16:37:04 by mhoussas          #+#    #+#             */
/*   Updated: 2025/06/14 23:01:42 by mhoussas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

char	*ft_extract_command(t_token *lst)
{
	while (lst)
	{
		if (lst->type == TOKEN_PIPE)
			break ;
		else if (lst->type == TOKEN_RED_IN || lst->type == TOKEN_RED_OUT
			|| lst->type == TOKEN_RED_APP || lst->type == TOKEN_HEREDOC)
			lst = lst->next;
		else if (lst->type == TOKEN_WORD && lst->value)
			return (lst->value);
		if (lst)
			lst = lst->next;
	}
	return (NULL);
}
