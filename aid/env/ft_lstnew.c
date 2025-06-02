/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoussas <mhoussas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 15:16:37 by mhoussas          #+#    #+#             */
/*   Updated: 2025/06/02 12:29:51 by mhoussas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

t_env	*ft_lstnew_env(char *name, char *value, int active)
{
	t_env	*res;

	res = malloc(sizeof(t_env));
	if (!res)
		ft_exit(1);
	res->name = name;
	res->value = value;
	res->active = active;
	res->next = NULL;
	return (res);
}
