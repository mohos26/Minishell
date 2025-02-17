/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoussas <mhoussas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 09:29:49 by mhoussas          #+#    #+#             */
/*   Updated: 2025/02/17 14:40:01 by mhoussas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void	*free_array(char **ptr, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		free(ptr[i]);
		i++;
	}
	free(ptr);
	return (NULL);
}

static int	count_word(const char *s, char c)
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

static int	find(const char *s, char c)
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
	res = (char **)malloc((count_word(s, c) + 1) * sizeof(char *));
	if (!res)
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			res[i] = (char *)malloc((find(s, c) + 1) * sizeof(char));
			if (!res[i])
				return (free_array(res, i));
			ft_memcpy(res[i], s, find(s, c));
			res[i++][find(s, c)] = '\0';
			s += find(s, c);
		}
	}
	res[i] = NULL;
	return (res);
}
