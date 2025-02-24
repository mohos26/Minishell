/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage_collector.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoussas <mhoussas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 08:59:44 by mhoussas          #+#    #+#             */
/*   Updated: 2025/02/24 15:43:07 by mhoussas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

static void	ft_free(void *ptr, int flag)
{
	static void	*lst[10000];
	static int	i;
	int			d;

	if (flag)
	{
		d = 0;
		while (lst[d])
			free(lst[d++]);
	}
	else
		lst[i++] = ptr;
}

void	ft_exit(int status)
{
	ft_free(NULL, 1);
	exit(status);
}

void	*ft_calloc(size_t size)
{
	void	*ptr;

	ptr = malloc(size);
	if (!ptr)
		ft_exit(1);
	ft_bzero(ptr, size);
	ft_free(ptr, 0);
	return (ptr);
}
