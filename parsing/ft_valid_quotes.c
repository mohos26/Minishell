/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid_quotes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoussas <mhoussas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 21:46:17 by mhoussas          #+#    #+#             */
/*   Updated: 2025/05/19 21:52:22 by mhoussas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	ft_valid_quotes(char *s)
{
	while (*s)
	{
		if (*s == '"')
		{
			s++;
			s = ft_strchr(s, '"');
			if (!s)
				return (0);
		}
		else if (*s == '\'')
		{
			s++;
			s = ft_strchr(s, '\'');
			if (!s)
				return (0);
		}
		s++;
	}
	return (1);
}
