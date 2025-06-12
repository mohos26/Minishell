/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe_wait.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoussas <mhoussas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 18:04:20 by mhoussas          #+#    #+#             */
/*   Updated: 2025/06/12 18:06:06 by mhoussas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

static int	ft_aid(int status)
{
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

int	ft_pipe_wait(int *pid_lst)
{
	int		last_pid;
	int		wstatus;
	int		status;
	pid_t	pid;

	while (pid_lst && *pid_lst)
		last_pid = *pid_lst++;
	status = 0;
	while (1)
	{
		pid = wait(&wstatus);
		wstatus = ft_aid(wstatus);
		if (pid <= 0)
			break ;
		if (pid == last_pid)
			status = wstatus;
	}
	return (status);
}
