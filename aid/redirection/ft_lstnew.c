/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoussas <mhoussas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 15:16:37 by mhoussas          #+#    #+#             */
/*   Updated: 2025/04/15 17:01:53 by mhoussas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

t_red	*ft_lstnew_red(char *name, int value)
{
	t_red	*res;

	res = ft_calloc(sizeof(t_red));
	if (!res)
		return (NULL);
	res->file_name = name;
	res->flag = value;
	res->next = NULL;
	return (res);
}
