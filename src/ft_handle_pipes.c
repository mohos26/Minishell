/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_pipes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoussas <mhoussas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 18:02:12 by mhoussas          #+#    #+#             */
/*   Updated: 2025/05/28 21:47:51 by mhoussas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

static void	ft_execute_child(t_prompt *prompt, int *pipefd, int in_fd, int i)
{
	dup2(in_fd, STDIN_FILENO);
	if (i < prompt->length - 1)
	{
		dup2(pipefd[1], STDOUT_FILENO);
		close(in_fd);
		close(pipefd[0]);
		close(pipefd[1]);
	}
	ft_exit(ft_process_command(prompt->args[i]));
}

static int	ft_wait(int last_pid)
{
	int		wstatus;
	int		status;
	pid_t	pid;

	status = 0;
	while (1)
	{
		pid = wait(&wstatus);
		if (pid <= 0)
			break ;
		if (pid == last_pid)
			status = wstatus;
	}
	return (WEXITSTATUS(status));
}

int	ft_handle_pipes(t_prompt *prompt)
{
	int		pipefd[2];
	int		last_pid;
	int		in_fd;
	pid_t	pid;
	int		i;

	i = 0;
	in_fd = dup(0);
	while (i < prompt->length)
	{
		if (i < prompt->length - 1)
			pipe(pipefd);
		pid = fork();
		if (pid == -1)
			return (ft_print_error("fork", "Resource temporarily unavailable",
					"Nothing"), ft_wait(last_pid), 1);
		if (!pid)
			ft_execute_child(prompt, pipefd, in_fd, i);
		if (i == prompt->length - 1)
			last_pid = pid;
		if (close(in_fd) * 0 || i < prompt->length - 1)
			in_fd = pipefd[0] + close(pipefd[1]) * 0;
		i++;
	}
	return (dup2(in_fd, STDIN_FILENO), close(in_fd), ft_wait(last_pid));
}
