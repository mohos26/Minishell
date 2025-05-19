/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_command.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoussas <mhoussas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 09:09:54 by mhoussas          #+#    #+#             */
/*   Updated: 2025/05/19 20:08:29 by mhoussas         ###   ########.fr       */
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

int	ft_not_valid(t_args *args)
{
	int		status;
	char	*aid;

	status = 126;
	aid = args->frist;
	if (!ft_strlen(ft_getenv("PATH")))
		if (*aid && !ft_strchr(aid, '/'))
			aid = ft_strjoin("./", aid);
	if (!ft_strchr(aid, '/'))
	{
		ft_print_error(args->frist, "command not found", "Nothing");
		status = 127;
	}
	else if (ft_check_dir(aid))
		ft_print_error(args->frist, "is a directory", "Nothing");
	else if (!access(aid, F_OK) && access(aid, X_OK))
		ft_print_error(args->frist, "permission denied", "Nothing");
	else
	{
		if (errno == 2)
			status = 127;
		ft_print_error(args->frist, strerror(errno), "Nothing");
	}
	return (status);
}

int	ft_process_command(t_args *args)
{
	int		status;

	status = 0;
	if (!args->valid && args->frist)
		return (ft_not_valid(args));
	(ft_stdin(1), ft_stdout(1));
	if (ft_do_redirection(args->_redirections))
		return (1);
	if (args->is_sh)
		status = ft_do_sh(args);
	else if (args->is_cmd)
	{
		status = ft_execute(args);
		status = WEXITSTATUS(status);
	}
	(ft_stdin(0), ft_stdout(0));
	return (status);
}
