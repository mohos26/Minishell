/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaliari <amaliari@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-05-23 10:04:06 by amaliari          #+#    #+#             */
/*   Updated: 2025-05-23 10:04:06 by amaliari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

char	*ft_expand_quotes(char *var)
{
	if (!ft_strlen(var))
		var = ft_strdup("$");
	else
		var = ft_getenv(var);
	if (var)
		return (var);
	return ("");
}

char	*ft_expand_split(t_token **lst, char *aid, char *var, int flag)
{
	char	**aid2;
	char	*aid3;
	int		len;
	int		i;

	len = 0;
	aid3 = ft_getenv(var);
	if (!ft_strlen(var) && flag)
		aid3 = ft_strdup("$");
	aid2 = ft_split(aid3, ' ');
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
