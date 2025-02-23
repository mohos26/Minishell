/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoussas <mhoussas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 11:02:48 by mhoussas          #+#    #+#             */
/*   Updated: 2025/02/23 09:34:37 by mhoussas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	sh_cd(char *s)
{
	DIR	*ptr;

	ptr = opendir(s);
	if (ptr)
	{
		chdir(s);
		closedir(ptr);
	}
	else
	{
		access(s, F_OK);
		ft_print_error("cd", s, NULL);
	}
}
