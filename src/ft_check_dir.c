/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_dir.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoussas <mhoussas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 22:25:13 by mhoussas          #+#    #+#             */
/*   Updated: 2025/05/06 22:50:14 by mhoussas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	ft_check_dir(char *s)
{
	int	fd;
	int	res;

	res = 1;
	fd = open(s, O_DIRECTORY);
	if (fd == -1)
		res = 0;
	close(fd);
	return (res);
}
