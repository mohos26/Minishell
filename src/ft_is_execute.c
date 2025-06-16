/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_execute.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoussas <mhoussas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 15:00:29 by mhoussas          #+#    #+#             */
/*   Updated: 2025/06/15 21:50:55 by mhoussas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

static char	*ft_aid(void)
{
	char	*paths;

	paths = ft_getenv("PATH");
	if (!paths || !*paths)
		return (".");
	return (paths);
}

static int	ft_aid2(t_args *args, char *path)
{
	if (access(path, X_OK))
		return (-1);
	args->frist = path;
	return (1);
}

int	ft_is_execute(t_args *args)
{
	char	**lst;
	char	*path;
	char	*s;

	if (args->is_sh)
		return (0);
	s = args->frist;
	if (!s || !*s || ft_check_dir(s))
		return (0);
	if (ft_strchr(s, '/'))
		return (!access(s, X_OK));
	lst = ft_split(ft_aid(), ':');
	s = ft_strjoin("/", s);
	while (lst && *lst)
	{
		path = ft_strjoin(*lst, s);
		if (!access(path, F_OK))
			return (ft_aid2(args, path));
		lst++;
	}
	return (0);
}
