/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoussas <mhoussas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 15:16:37 by mhoussas          #+#    #+#             */
/*   Updated: 2025/06/15 11:14:43 by mhoussas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

t_token	*ft_lstnew_token(char *value, int type, int flag)
{
	t_token	*res;

	res = (t_token *) ft_calloc(sizeof(t_token));
	if (!res)
		return (NULL);
	res->value = value;
	res->type = type;
	res->flag = flag;
	res->next = NULL;
	return (res);
}
