/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_command.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoussas <mhoussas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 09:09:54 by mhoussas          #+#    #+#             */
/*   Updated: 2025/06/04 13:38:50 by mhoussas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

static int	ft_aid(t_args *args)
{
	int	status;

	status = ft_execute(args);
	if (WIFEXITED(status))
		status = WEXITSTATUS(status);
	else if (WIFSIGNALED(status))
	{
		status = 128 + WTERMSIG(status);
		g_last_signal_received = WTERMSIG(status);
	}
	else
		status = 1;
	return (status);
}

int	ft_process_command(t_args *args)
{
	int		status;
	int		out_fd;
	int		in_fd;

	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
	status = 0;
	in_fd = dup(0);
	out_fd = dup(1);
	if (ft_do_redirection(args->_redirections))
		return (dup2(in_fd, 0), dup2(out_fd, 1), 1);
	if (!args->valid && args->frist)
		return (dup2(in_fd, 0), dup2(out_fd, 1), ft_not_valid(args));
	if (args->is_sh)
		status = ft_do_sh(args);
	else if (args->is_cmd > 0)
		status = ft_aid(args);
	(dup2(in_fd, 0), dup2(out_fd, 1));
	return (status);
}
