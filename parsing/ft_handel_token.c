/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handel_token.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoussas <mhoussas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 13:04:54 by mhoussas          #+#    #+#             */
/*   Updated: 2025/05/22 13:20:37 by mhoussas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	ft_handle_token(t_token **lst, char **aid, char **var, int type)
{
	char	*str;

	if (type == TOKEN_PIPE)
		str = "|";
	else if (type == TOKEN_RED_IN)
		str = "<";
	else if (type == TOKEN_RED_OUT)
		str = ">";
	else if (type == TOKEN_HEREDOC)
		str = "<<";
	else if (type == TOKEN_RED_APP)
		str = ">>";
	if (*var)
		*aid = ft_expand_split(lst, *aid, *var);
	*var = NULL;
	if (*aid && **aid)
		ft_lstadd_back_token(lst, ft_lstnew_token(*aid, TOKEN_WORD));
	*aid = NULL;
	ft_lstadd_back_token(lst, ft_lstnew_token(ft_strdup(str), type));
}
