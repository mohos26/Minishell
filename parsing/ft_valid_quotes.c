/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid_quotes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaliari <amaliari@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-05-23 10:04:02 by amaliari          #+#    #+#             */
/*   Updated: 2025-05-23 10:04:02 by amaliari         ###   ########.fr       */
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
