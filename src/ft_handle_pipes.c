/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_pipes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoussas <mhoussas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 18:02:12 by mhoussas          #+#    #+#             */
/*   Updated: 2025/06/04 13:39:27 by mhoussas         ###   ########.fr       */
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

static char	**ft_create_lst(char *frist, char **args)
{
	char	**head;
	char	**res;
	int		len;

	len = 0;
	while (args && args[len])
		len++;
	res = ft_calloc(sizeof(char *) * (len + 2));
	head = res;
	*res++ = frist;
	while (len--)
		*res++ = *args++;
	*res = NULL;
	return (head);
}

static int	ft_process_command_pipe(t_args *args)
{
	int		status;
	char	**lst;

	status = 0;
	if (ft_do_redirection(args->_redirections))
		return (1);
	if (!args->valid && args->frist)
		return (ft_not_valid(args));
	if (args->is_sh)
		status = ft_do_sh(args);
	else if (args->is_cmd > 0)
	{
		lst = ft_create_lst(args->frist, args->args);
		signal(SIGINT, SIG_DFL);
		signal(SIGQUIT, SIG_DFL);
		execve(*lst, lst, ft_convert_env());
		perror("Execve failed");
		status = 1;
	}
	return (status);
}

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
	ft_exit(ft_process_command_pipe(prompt->args[i]));
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
		wstatus = ft_aid(wstatus);
		if (pid <= 0)
			break ;
		if (pid == last_pid)
			status = wstatus;
	}
	return (status);
}

static void	ft_fork_fail(int *lst)
{
	while (lst && *lst)
	{
		kill(*lst, SIGKILL);
		waitpid(*lst, NULL, 0);
		lst++;
	}
}

int	ft_handle_pipes(t_prompt *prompt)
{
	int		pipefd[2];
	int		last_pid;
	int		*pid_lst;
	int		in_fd;
	pid_t	pid;
	int		i;

	i = 0;
	in_fd = dup(0);
	pid_lst = NULL;
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
	while (i < prompt->length)
	{
		if (i < prompt->length - 1)
			pipe(pipefd);
		pid = fork();
		if (pid == -1)
			return (ft_print_error("fork", "Resource temporarily unavailable",
					"Nothing"), ft_fork_fail(pid_lst), 1);
		if (!pid)
			ft_execute_child(prompt, pipefd, in_fd, i);
		pid_lst = ft_append_int(pid_lst, pid);
		if (i == prompt->length - 1)
			last_pid = pid;
		if (close(in_fd) * 0 || i < prompt->length - 1)
			in_fd = pipefd[0] + close(pipefd[1]) * 0;
		i++;
	}
	return (dup2(in_fd, STDIN_FILENO), close(in_fd), ft_wait(last_pid));
}
