/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getcwd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoussas <mhoussas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 18:34:06 by mhoussas          #+#    #+#             */
/*   Updated: 2025/05/23 10:11:02 by mhoussas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

char	*ft_getcwd(char *s, size_t n)
{
	char	*res;
	char	*tmp;

	tmp = getcwd(s, n);
	if (!tmp)
		return (NULL);
	res = ft_strdup(tmp);
	free(tmp);
	return (res);
}
