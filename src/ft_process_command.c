/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_command.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoussas <mhoussas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 09:09:54 by mhoussas          #+#    #+#             */
/*   Updated: 2025/05/18 18:01:00 by mhoussas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	ft_not_valid(t_args *args)
{
	char	*aid;
	int		status;

	status = 127;
	aid = args->frist;
	if (!ft_strlen(ft_getenv("PATH")))
		if (!ft_strchr(aid, '/'))
			aid = ft_strjoin(aid, "/");
	if (ft_check_dir(aid) && ft_strchr(aid, '/'))
	{
		status = 126;
		ft_print_error(args->frist, "is a directory", "Nothing");
	}
	else if (ft_strchr(aid, '/'))
		ft_print_error(args->frist, "No such file or directory", "Nothing");
	else
		ft_print_error(args->frist, "command not found", "Nothing");
	return (status);
}

int	ft_process_command(t_args *args)
{
	char	*aid;
	int		status;

	status = 0;
	aid = args->frist;
	if (!args->valid && args->frist)
		return (ft_not_valid(args));
	if (ft_do_redirection(args->_redirections))
		return (1);
	if (args->is_sh)
		status = ft_do_sh(args);
	else if (args->is_cmd)
	{
		status = ft_execute(args);
		status = WEXITSTATUS(status);
	}
	ft_close_redirection(args->_redirections);
	return (status);
}
