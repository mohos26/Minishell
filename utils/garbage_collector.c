/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage_collector.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoussas <mhoussas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 08:59:44 by mhoussas          #+#    #+#             */
/*   Updated: 2025/05/11 17:11:40 by mhoussas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

static void	ft_free(void *ptr, int flag)
{
	static void	*lst[INT_MAX];
	static int	i;

	if (flag)
	{
		while (i)
		{
			free(lst[--i]);
			lst[i] = NULL;
		}
	}
	else
		lst[i++] = ptr;
}

void	ft_clean(void)
{
	ft_free(NULL, 1);
}

void	ft_exit(int status)
{
	t_env	*lst;

	ft_free(NULL, 1);
	lst = *ft_env(NULL);
	while (lst)
	{
		free(lst->name);
		free(lst->value);
		free(lst);
		lst = lst->next;
	}
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
