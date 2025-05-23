/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_here_doc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoussas <mhoussas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 15:04:40 by mhoussas          #+#    #+#             */
/*   Updated: 2025/05/23 22:51:23 by mhoussas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

static char	*ft_expand(char *var)
{
	if (!var)
		return (NULL);
	var = ft_getenv(var);
	if (var)
		return (var);
	return ("");
}

static char	*ft_aid(char *prompt)
{
	char	*res;
	char	*var;
	int		flag;

	flag = 0;
	var = NULL;
	res = NULL;
	while (prompt && *prompt)
	{
		if (*prompt == '$' && !flag)
			flag = 1;
		else if (flag && ft_is_valid(var, *prompt))
			var = ft_append_str(var, *prompt);
		else if (flag)
		{
			if (var)
				res = ft_strjoin(res, ft_expand(var));
			var = NULL;
			prompt -= flag--;
		}
		else
			res = ft_append_str(res, *prompt);
		prompt++;
	}
	return (ft_strjoin(res, ft_expand(var)));
}

static void	ft_child(int *fds, char *limiter)
{
	char	*res;
	char	*aid;

	res = NULL;
	signal(SIGINT, ft_heredoc_signal);
	while (1)
	{
		aid = ft_readline("> ");
		if (!ft_strncmp(aid, limiter, INT_MAX) || (!ft_strlen(aid)
				&& !ft_strlen(limiter)))
			break ;
		aid = ft_aid(aid);
		if (res)
			res = ft_strjoin(ft_strjoin(res, "\n"), aid);
		else
			res = ft_strjoin(res, aid);
	}
	if (res)
		res = ft_strjoin(res, "\n");
	ft_putstr_fd(res, fds[1]);
	close(fds[1]);
	close(fds[0]);
	ft_exit(0);
}

char	*ft_here_doc(char *limiter)
{
	int		status;
	int		fds[2];
	pid_t	pid;

	pipe(fds);
	pid = fork();
	if (pid == -1)
		return (ft_print_error("fork", "Resource temporarily unavailable",
				"Nothing"), NULL);
	signal(SIGINT, SIG_IGN);
	if (!pid)
		ft_child(fds, limiter);
	close(fds[1]);
	waitpid(pid, &status, 0);
	signal(SIGINT, ft_signal_handler);
	if (WIFEXITED(status) && WEXITSTATUS(status) == 1)
	{
		close(fds[0]);
		return (NULL);
	}
	return (ft_itoa(fds[0]));
}
