/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirection_cmd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoussas <mhoussas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 11:49:11 by mhoussas          #+#    #+#             */
/*   Updated: 2025/05/18 14:47:32 by mhoussas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

static void	ft_stdin(int flag)
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

static void	ft_stdout(int flag)
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

int	ft_do_redirection(t_red *lst)
{
	char	*file_redirections;
	int		redirections;
	int		fd;

	if (!lst)
		return (0);
	redirections = lst->flag;
	file_redirections = lst->file_name;
	if (redirections == 1)
		fd = open(file_redirections, O_RDONLY, 0644);
	else if (redirections == 2)
		fd = open(file_redirections, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	else if (redirections == 3)
		fd = open(file_redirections, O_CREAT | O_WRONLY | O_APPEND, 0644);
	else
		return (1);
	if (fd == -1)
		return (perror(ft_strjoin("Minishell: ", file_redirections)), 1);
	if (redirections == 1)
		(ft_stdin(1), dup2(fd, 0));
	else
		(ft_stdout(1), dup2(fd, 1));
	close(fd);
	return (ft_do_redirection(lst->next));
}

void	ft_close_redirection(t_red *lst)
{
	int	redirections;

	if (!lst)
		return ;
	redirections = lst->flag;
	if (redirections == 1)
		ft_stdin(0);
	else if (redirections >= 2)
		ft_stdout(0);
	return (ft_close_redirection(lst->next));
}
