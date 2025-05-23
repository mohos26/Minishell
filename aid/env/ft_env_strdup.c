/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_strdup.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoussas <mhoussas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 18:07:12 by mhoussas          #+#    #+#             */
/*   Updated: 2025/05/22 15:44:55 by mhoussas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

char	*ft_env_strdup(char *s)
{
	char	*ptr;
	char	*head;

	ptr = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!ptr)
		ft_exit(1);
	head = ptr;
	while (s && *s)
		*ptr++ = *s++;
	*ptr = '\0';
	return (head);
}
