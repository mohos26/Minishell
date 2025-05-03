/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_prompt.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoussas <mhoussas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 09:10:28 by mhoussas          #+#    #+#             */
/*   Updated: 2025/05/03 17:04:44 by mhoussas         ###   ########.fr       */
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
	ft_process_command(prompt->args[i]);
	ft_exit(0);
}

static void	ft_handle_pipes(t_prompt *prompt)
{
	int		pipefd[2];
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
		close(in_fd);
		if (i < prompt->length - 1)
		{
			close(pipefd[1]);
			in_fd = pipefd[0];
		}
		i++;
	}
	(dup2(in_fd, STDIN_FILENO), close(in_fd));
	while (wait(NULL) > 0)
		;
}

void	ft_process_prompt(t_prompt *prompt)
{
	if (prompt->length == 1)
	{
		ft_process_command(*(prompt->args));
		waitpid(-1, NULL, 0);
		return ;
	}
	ft_handle_pipes(prompt);
}
