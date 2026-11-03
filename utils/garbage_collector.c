/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage_collector.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoussas <mhoussas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 08:59:44 by mhoussas          #+#    #+#             */
/*   Updated: 2025/06/01 15:31:12 by mhoussas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

#ifndef OPEN_MAX
# define OPEN_MAX 1024
#endif

static void	ft_free(void *ptr, int flag)
{
	static void	**lst;
	static size_t	count;
	static size_t	capacity;
	void		**new_lst;
	size_t		j;

	if (flag)
	{
		j = 0;
		while (j < count)
		{
			free(lst[j]);
			j++;
		}
		free(lst);
		lst = NULL;
		count = 0;
		capacity = 0;
	}
	else
	{
		if (count == capacity)
		{
			if (capacity == 0)
				capacity = 64;
			else
				capacity *= 2;
			new_lst = realloc(lst, capacity * sizeof(*lst));
			if (!new_lst)
				ft_exit(1);
			lst = new_lst;
		}
		lst[count++] = ptr;
	}
}

void	ft_clean(void)
{
	int	fd;

	fd = 3;
	while (fd <= OPEN_MAX)
		close(fd++);
	ft_free(NULL, 1);
	ft_signal_util();
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
