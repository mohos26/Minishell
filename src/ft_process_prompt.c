/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_prompt.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoussas <mhoussas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 09:10:28 by mhoussas          #+#    #+#             */
/*   Updated: 2025/05/19 18:49:34 by mhoussas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

static void	ft_execute_child(t_prompt *prompt, int *pipefd, int in_fd, int i)
{
	int	status;

	dup2(in_fd, STDIN_FILENO);
	if (i < prompt->length - 1)
	{
		dup2(pipefd[1], STDOUT_FILENO);
		close(in_fd);
		close(pipefd[0]);
		close(pipefd[1]);
	}
	status = ft_process_command(prompt->args[i]);
	ft_exit(status);
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

static int	ft_handle_pipes(t_prompt *prompt)
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
		if (!pid)
			ft_execute_child(prompt, pipefd, in_fd, i);
		if (i == prompt->length - 1)
			last_pid = pid;
		close(in_fd);
		if (i < prompt->length - 1)
			in_fd = pipefd[0] + close(pipefd[1]) * 0;
		i++;
	}
	(dup2(in_fd, STDIN_FILENO), close(in_fd));
	return (ft_wait(last_pid));
}

int	ft_process_prompt(t_prompt *prompt)
{
	if (!prompt)
		return (258);
	if (prompt->length == 1)
		return (ft_process_command(*(prompt->args)));
	return (ft_handle_pipes(prompt));
}
