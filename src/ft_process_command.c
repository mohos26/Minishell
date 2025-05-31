/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_command.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoussas <mhoussas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 09:09:54 by mhoussas          #+#    #+#             */
/*   Updated: 2025/05/27 09:51:19 by mhoussas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

static int	ft_not_valid(t_args *args)
{
	int		status;
	char	*aid;

	status = 126;
	aid = args->frist;
	if (!ft_strlen(ft_getenv("PATH")))
		if (*aid && !ft_strchr(aid, '/'))
			aid = ft_strjoin("./", aid);
	if (!ft_strchr(aid, '/'))
	{
		ft_print_error(args->frist, "command not found", "Nothing");
		status = 127;
	}
	else if (ft_check_dir(aid))
		ft_print_error(args->frist, "is a directory", "Nothing");
	else if (!access(aid, F_OK) && access(aid, X_OK))
		ft_print_error(args->frist, "Permission denied", "Nothing");
	else
	{
		if (errno == 2)
			status = 127;
		ft_print_error(args->frist, strerror(errno), "Nothing");
	}
	return (status);
}

int	ft_process_command(t_args *args)
{
	int		status;
	int		out_fd;
	int		in_fd;

	status = 0;
	in_fd = dup(0);
	out_fd = dup(1);
	if (ft_do_redirection(args->_redirections))
		return (dup2(in_fd, 0), dup2(out_fd, 1), 1);
	if (!args->valid && args->frist)
		return (dup2(in_fd, 0), dup2(out_fd, 1), ft_not_valid(args));
	if (args->is_sh)
		status = ft_do_sh(args);
	else if (args->is_cmd)
	{
		status = ft_execute(args);
		status = WEXITSTATUS(status);
	}
	if (ft_atoi(ft_getenv("1ctrl")))
		status = ft_atoi(ft_getenv("?"));
	ft_update_ctrl_flag(0);
	(dup2(in_fd, 0), dup2(out_fd, 1));
	return (status);
}
