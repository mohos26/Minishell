/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirection_cmd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoussas <mhoussas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 11:49:11 by mhoussas          #+#    #+#             */
/*   Updated: 2025/05/22 15:23:08 by mhoussas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

static int	ft_aid(char *file_redirections, int flag)
{
	if (flag)
		return (ft_atoi(file_redirections));
	return (open(file_redirections, O_RDONLY));
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
		fd = ft_aid(file_redirections, lst->flag2);
	else if (redirections == 2)
		fd = open(file_redirections, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	else if (redirections == 3)
		fd = open(file_redirections, O_CREAT | O_WRONLY | O_APPEND, 0644);
	else
		return (1);
	if (fd == -1)
		return (perror(ft_strjoin("Minishell: ", file_redirections)), 1);
	if (redirections == 1)
		(dup2(fd, 0));
	else
		(dup2(fd, 1));
	close(fd);
	return (ft_do_redirection(lst->next));
}
