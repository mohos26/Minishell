/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirection_pipe.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoussas <mhoussas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 08:20:31 by mhoussas          #+#    #+#             */
/*   Updated: 2025/03/12 09:47:37 by mhoussas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

static	void	ft_stdin(int flag)
{
	static int	status;
	static int	std;

	if (flag)
	{
		if (!status)
			std = dup(0);
		status = 1;
	}
	else
	{
		dup2(std, 0);
		close(std);
		status = 0;
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

void	ft_pipe_redirection(int fd, int flag)
{
	if (flag)
	{
		ft_stdin(1);
		dup2(fd, 1);
	}
	else
	{
		ft_stdout(1);
		dup2(fd, 0);
	}
	close(fd);
}

void	ft_close_pipe_redirection(int flag)
{
	if (flag)
		ft_stdout(0);
	else
		ft_stdin(0);
}
