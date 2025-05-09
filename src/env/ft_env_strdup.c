/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_strdup.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoussas <mhoussas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 18:07:12 by mhoussas          #+#    #+#             */
/*   Updated: 2025/04/30 18:07:22 by mhoussas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

char	*ft_env_strdup(char *s)
{
	char	*ptr;
	char	*head;

	ptr = malloc(ft_strlen(s) * sizeof(char) + 1);
	if (!ptr)
		ft_exit(1);
	head = ptr;
	while (*s)
		*ptr++ = *s++;
	*ptr = '\0';
	return (head);
}
