/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_command.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoussas <mhoussas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 09:09:54 by mhoussas          #+#    #+#             */
/*   Updated: 2025/03/12 09:10:14 by mhoussas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	ft_process_command(t_args *args)
{
	if (!args->valid)
	{
		ft_putstr_fd("No Valid\n", 2);
		return ;
	}
	ft_do_redirection(args);
	if (args->is_sh)
		ft_do_sh(args);
	else if (args->is_cmd)
		ft_execute(args);
	ft_close_redirection(args);
}
