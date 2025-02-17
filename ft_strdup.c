/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoussas <mhoussas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 17:29:16 by mhoussas          #+#    #+#             */
/*   Updated: 2025/02/17 14:47:14 by mhoussas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*ft_strdup(const char *s1)
{
	char	*ptr;
	char	*head;

	ptr = (char *) malloc(ft_strlen(s1) * sizeof(char) + 1);
	if (!ptr)
		return (NULL);
	head = ptr;
	while (*s1)
		*ptr++ = *s1++;
	*ptr = '\0';
	return (head);
}
