/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoussas <mhoussas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 12:52:56 by mhoussas          #+#    #+#             */
/*   Updated: 2025/05/23 07:47:17 by mhoussas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

char	*ft_expand_quotes(char *var)
{
	var = ft_getenv(var);
	if (var)
		return (var);
	return ("");
}

char	*ft_expand_split(t_token **lst, char *aid, char *var)
{
	char	**aid2;
	int		len;
	int		i;

	len = 0;
	aid2 = ft_split(ft_getenv(var), ' ');
	while (aid2 && aid2[len])
		len++;
	i = 0;
	while (i < len -1)
	{
		ft_lstadd_back_token(lst, ft_lstnew_token(ft_strjoin(aid, aid2[i]), 0));
		aid = NULL;
		i++;
	}
	if (len)
		return (ft_strjoin(aid, aid2[len - 1]));
	return (aid);
}

int	ft_is_valid(char *s, char c)
{
	if (!ft_strlen(s) && (c == '?' || ft_isalpha(c) || c == '_'))
		return (1);
	else if (ft_strlen(s) && (ft_isalnum(c) || c == '_') && *s != '?')
		return (1);
	return (0);
}

int	ft_is_space(char c)
{
	if (c == 32 || (c >= 9 && c <= 13))
		return (1);
	return (0);
}
