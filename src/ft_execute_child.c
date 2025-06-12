/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute_child.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoussas <mhoussas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 18:05:29 by mhoussas          #+#    #+#             */
/*   Updated: 2025/06/12 18:08:34 by mhoussas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

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

void	ft_execute_child(t_prompt *prompt, int *pipefd, int in_fd, int i)
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
