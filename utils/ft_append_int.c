/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_append_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoussas <mhoussas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 12:19:32 by mhoussas          #+#    #+#             */
/*   Updated: 2025/06/04 12:28:42 by mhoussas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	*ft_append_int(int *lst, int n)
{
	int	*res;
	int	len;
	int	i;

	len = 0;
	while (lst && lst[len])
		len++;
	res = ft_calloc(sizeof(int) * (len + 2));
	i = 0;
	while (i < len)
	{
		res[i] = lst[i];
		i++;
	}
	res[i++] = n;
	res[i] = 0;
	return (res);
}
