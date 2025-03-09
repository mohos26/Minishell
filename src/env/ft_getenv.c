/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoussas <mhoussas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 14:30:21 by mhoussas          #+#    #+#             */
/*   Updated: 2025/03/09 14:40:04 by mhoussas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

t_list	**ft_getenv(t_list *lst)
{
	static t_list	*env;

	if (!lst)
		return (&env);
	env = lst;
	return (NULL);
}
