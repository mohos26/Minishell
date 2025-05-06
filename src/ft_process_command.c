/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_command.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoussas <mhoussas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 09:09:54 by mhoussas          #+#    #+#             */
/*   Updated: 2025/05/06 22:48:50 by mhoussas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	ft_process_command(t_args *args)
{
	char	*aid;

	aid = args->frist;
	if (!args->valid)
	{
		ft_putstr_fd("No Valid\n", 2);
		if (!ft_strlen(ft_getenv("PATH")))
			if (!ft_strchr(aid, '/'))
				aid = ft_strjoin(aid, "/");
		if (ft_check_dir(aid) && ft_strchr(aid, '/'))
			return (ft_print_error(args->frist, "is a directory", "Nothing"));
		if (ft_strchr(aid, '/'))
			ft_print_error(args->frist, "No such file or directory", "Nothing");
		else
			ft_print_error(args->frist, "command not found", "Nothing");
		return ;
	}
	ft_do_redirection(args);
	if (args->is_sh)
		ft_do_sh(args);
	else if (args->is_cmd)
		ft_execute(args);
	ft_close_redirection(args);
}
