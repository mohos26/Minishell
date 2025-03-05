/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoussas <mhoussas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 17:11:07 by mhoussas          #+#    #+#             */
/*   Updated: 2025/03/01 08:36:14 by mhoussas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	ft_atoi(const char *str)
{
	int				signe;
	unsigned long	result;

	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	result = 0;
	signe = 1;
	if (*str == '-' || *str == '+')
	{
		if (*str++ == '-')
			signe = -1;
	}
	while (*str >= '0' && *str <= '9')
	{
		if (result > 922337203685477580
			|| (result == 922337203685477580 && (*str - '0') > 7))
		{
			if (signe == 1)
				return (-1);
			return (0);
		}
		result = (result * 10) + (*str - '0');
		str++;
	}
	return ((int)(result * signe));
}
