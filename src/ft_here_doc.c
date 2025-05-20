/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_here_doc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoussas <mhoussas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 15:04:40 by mhoussas          #+#    #+#             */
/*   Updated: 2025/05/20 15:17:34 by mhoussas         ###   ########.fr       */
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

static int	ft_is_valid(char *s, char c)
{
	if (!ft_strlen(s) && (c == '?' || ft_isalpha(c) || c == '_'))
		return (1);
	else if ((ft_isalnum(c) || c == '_') && *s != '?')
		return (1);
	return (0);
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

static void	ft_child(char *name_file, char *limiter)
{
	char	*res;
	char	*aid;
	int		fd;

	res = NULL;
	fd = open(name_file, O_CREAT | O_WRONLY, 0644);
	while (1)
	{
		aid = readline("> ");
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
	ft_putstr_fd(res, fd);
	close(fd);
	ft_exit(0);
}

char	*ft_here_doc(char *limiter)
{
	char	*name_file;
	pid_t	pid;
	int		n;

	n = 1;
	while (!access(ft_strjoin("/tmp/.herdoc", ft_itoa(n)), F_OK))
		n++;
	name_file = ft_strjoin("/tmp/.herdoc", ft_itoa(n));
	pid = fork();
	if (!pid)
		ft_child(name_file, limiter);
	wait(NULL);
	return (name_file);
}
