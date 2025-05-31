/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_wspace.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoussas <mhoussas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 15:15:01 by mhoussas          #+#    #+#             */
/*   Updated: 2025/05/31 15:21:57 by mhoussas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

static int	ft_count_word(const char *s)
{
	int	count;

	count = 0;
	while (*s)
	{
		while (ft_is_space(*s))
			s++;
		if (*s)
		{
			count++;
			while (*s && !ft_is_space(*s))
				s++;
		}
	}
	return (count);
}

static int	ft_find(const char *s)
{
	int	res;

	res = 0;
	while (s[res] && !ft_is_space(s[res]))
		res++;
	return (res);
}

char	**ft_split_wspace(const char *s)
{
	char	**res;
	int		i;

	if (!s)
		return (NULL);
	res = ft_calloc((ft_count_word(s) + 1) * sizeof(char *));
	i = 0;
	while (*s)
	{
		while (ft_is_space(*s))
			s++;
		if (*s)
		{
			res[i] = ft_calloc((ft_find(s) + 1) * sizeof(char));
			ft_memcpy(res[i], s, ft_find(s));
			res[i++][ft_find(s)] = '\0';
			s += ft_find(s);
		}
	}
	res[i] = NULL;
	return (res);
}
