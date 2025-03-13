/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_prompt.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoussas <mhoussas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 09:10:28 by mhoussas          #+#    #+#             */
/*   Updated: 2025/03/13 21:10:31 by mhoussas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

static void	ft_run_command(t_args *lst)
{
	pid_t	pid;

	pid = fork();
	if (!pid)
	{
		ft_process_command(lst);
		ft_exit(0);
	}
}

void	ft_create_pipe(int *fds)
{
	pipe(fds);
	dup2(fds[1], 1);
	close(fds[1]);
}

static void	ft_reset_io(int v_stdin, int v_stdout)
{
	dup2(v_stdin, 0);
	dup2(v_stdout, 1);
	close(v_stdin);
	close(v_stdout);
}

static void	ft_handle_pipes(t_prompt *prompt)
{
	int		v_stdout;
	int		v_stdin;
	int		fds[2];
	int		i;

	i = 0;
	v_stdin = dup(0);
	v_stdout = dup(1);
	while (i < prompt->length)
	{
		if (i)
		{
			dup2(fds[0], 0);
			close(fds[0]);
		}
		if (i < prompt->length - 1)
			ft_create_pipe(fds);
		else
			dup2(v_stdout, 1);
		ft_run_command((prompt->args)[i]);
		i++;
	}
	ft_reset_io(v_stdin, v_stdout);
	while (waitpid(-1, NULL, 0) > 0)
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
