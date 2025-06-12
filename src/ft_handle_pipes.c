/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_pipes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoussas <mhoussas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 18:02:12 by mhoussas          #+#    #+#             */
/*   Updated: 2025/06/12 18:08:19 by mhoussas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

static void	ft_fork_fail(int *lst)
{
	while (lst && *lst)
	{
		kill(*lst, SIGKILL);
		waitpid(*lst, NULL, 0);
		lst++;
	}
}

static int	*ft_local_init(int *i, int *in_fd)
{
	*i = 0;
	*in_fd = dup(0);
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
	return (NULL);
}

int	ft_handle_pipes(t_prompt *prompt)
{
	int		pipefd[2];
	int		*pid_lst;
	int		in_fd;
	pid_t	pid;
	int		i;

	pid_lst = ft_local_init(&i, &in_fd);
	while (i < prompt->length)
	{
		if (i < prompt->length - 1)
			pipe(pipefd);
		pid = fork();
		if (pid == -1)
			return (ft_print_error("fork", "Resource temporarily unavailable",
					"Nothing"), ft_fork_fail(pid_lst), 1);
		else if (!pid)
			ft_execute_child(prompt, pipefd, in_fd, i);
		pid_lst = ft_append_int(pid_lst, pid);
		if (close(in_fd) * 0 || i < prompt->length - 1)
			in_fd = pipefd[0] + close(pipefd[1]) * 0;
		i++;
	}
	return (dup2(in_fd, STDIN_FILENO), close(in_fd), ft_pipe_wait(pid_lst));
}
