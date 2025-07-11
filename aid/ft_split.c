/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoussas <mhoussas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 09:29:49 by mhoussas          #+#    #+#             */
/*   Updated: 2025/05/31 15:14:03 by mhoussas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

static int	ft_count_word(const char *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			count++;
			while (*s && *s != c)
				s++;
		}
	}
	return (count);
}

static int	ft_find(const char *s, char c)
{
	int	res;

	res = 0;
	while (s[res] && s[res] != c)
		res++;
	return (res);
}

char	**ft_split(const char *s, char c)
{
	char	**res;
	int		i;

	if (!s)
		return (NULL);
	res = ft_calloc((ft_count_word(s, c) + 1) * sizeof(char *));
	i = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			res[i] = ft_calloc((ft_find(s, c) + 1) * sizeof(char));
			ft_memcpy(res[i], s, ft_find(s, c));
			res[i++][ft_find(s, c)] = '\0';
			s += ft_find(s, c);
		}
	}
	res[i] = NULL;
	return (res);
}
