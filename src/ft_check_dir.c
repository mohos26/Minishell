/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_dir.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoussas <mhoussas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 22:25:13 by mhoussas          #+#    #+#             */
/*   Updated: 2025/05/29 22:25:09 by mhoussas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	ft_check_dir(char *s)
{
	DIR	*ptr;

	ptr = opendir(s);
	if (!ptr)
		return (0);
	return (closedir(ptr), 1);
}
