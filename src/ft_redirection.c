/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirection.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoussas <mhoussas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 11:49:11 by mhoussas          #+#    #+#             */
/*   Updated: 2025/03/05 15:26:27 by mhoussas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

static	void	ft_stdin(int flag)
{
	static int	std;

	if (flag)
		std = dup(0);
	else
	{
		dup2(std, 0);
		close(std);
	}
}

static	void	ft_stdout(int flag)
{
	static int	std;

	if (flag)
		std = dup(1);
	else
	{
		dup2(std, 1);
		close(std);
	}
}

void	ft_do_redirection(t_args *args)
{
	int	fd;

	if (args->redirections == 1)
		fd = open(args->file_redirections, O_RDONLY);
	else if (args->redirections == 2)
		fd = open(args->file_redirections, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	else if (args->redirections == 3)
		fd = open(args->file_redirections, O_CREAT | O_WRONLY | O_APPEND, 0644);
	else
		return ;
	if (args->redirections == 1)
	{
		ft_stdin(1);
		dup2(fd, 0);
	}
	else
	{
		ft_stdout(1);
		dup2(fd, 1);
	}
	close(fd);
}

void	ft_close_redirection(t_args *args)
{
	if (args->redirections == 1)
		ft_stdin(0);
	else if (args->redirections >= 2)
		ft_stdout(0);
}
