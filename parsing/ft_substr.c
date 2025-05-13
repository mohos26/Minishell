/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoussas <mhoussas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 09:49:23 by mhoussas          #+#    #+#             */
/*   Updated: 2025/05/13 06:43:18 by mhoussas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	length;
	char	*res;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	s += start;
	length = ft_strlen(s);
	if (length > len)
		length = len;
	res = (char *)malloc((length + 1) * sizeof(char));
	if (!res)
		return (NULL);
	ft_memcpy(res, s, length);
	res[length] = '\0';
	return (res);
}
