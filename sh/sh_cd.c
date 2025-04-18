/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoussas <mhoussas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 11:02:48 by mhoussas          #+#    #+#             */
/*   Updated: 2025/04/12 15:43:30 by mhoussas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	sh_cd(t_args *args)
{
	DIR		*ptr;
	char	*aid;

	if (!args->args || !*(args->args))
	{
		aid = ft_getenv("HOME");
		if (!aid)
			return (ft_print_error("cd", "HOME not set", "Nothing"));
		else if (!*aid)
			return ;
	}
	else
		aid = *(args->args);
	ptr = opendir(aid);
	if (ptr)
	{
		chdir(aid);
		closedir(ptr);
	}
	else
		ft_print_error("cd", aid, NULL);
}
