/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage_collector.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoussas <mhoussas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 08:59:44 by mhoussas          #+#    #+#             */
/*   Updated: 2025/05/22 18:35:45 by mhoussas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

static void	ft_free(void *ptr, int flag)
{
	static void	*lst[INT_MAX];
	static int	i;
	int			j;

	if (flag)
	{
		j = 0;
		while (j < i)
		{
			free(lst[j]);
			lst[j++] = NULL;
		}
		i = 0;
	}
	else
		lst[i++] = ptr;
}

void	ft_clean(void)
{
	int	fd;

	fd = 3;
	while (fd < 1025)
		close(fd++);
	ft_free(NULL, 1);
}

char	*ft_readline(char *s)
{
	char	*res;

	res = readline(s);
	ft_free(res, 0);
	return (res);
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
