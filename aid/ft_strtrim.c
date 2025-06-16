/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoussas <mhoussas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 11:39:25 by mhoussas          #+#    #+#             */
/*   Updated: 2025/06/15 18:17:26 by mhoussas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

char	*ft_strtrim(char const *s1)
{
	char	*aid;
	char	*res;
	int		start;
	int		end;

	if (!s1)
		return (NULL);
	aid = (char *)s1;
	start = 0;
	while (ft_is_space(aid[start]))
		start++;
	end = ft_strlen(aid) - 1;
	while (end > start && ft_is_space(aid[end]))
		end--;
	if (start > end)
		return (ft_strdup(""));
	res = ft_calloc((end - start + 2) * sizeof(char));
	ft_memcpy(res, aid + start, end - start + 1);
	res[end - start + 1] = '\0';
	return (res);
}
