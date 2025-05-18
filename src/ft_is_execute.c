/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_execute.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoussas <mhoussas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 15:00:29 by mhoussas          #+#    #+#             */
/*   Updated: 2025/05/17 08:47:59 by mhoussas         ###   ########.fr       */
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

int	ft_is_execute(t_args *args)
{
	char	**lst;
	char	*path;
	char	*s;

	if (args->is_sh)
		return (0);
	s = args->frist;
	if (!s || ft_check_dir(s))
		return (0);
	if (ft_strchr(s, '/'))
		return (!access(s, X_OK));
	lst = ft_split(ft_aid(), ':');
	s = ft_strjoin("/", s);
	while (lst && *lst)
	{
		path = ft_strjoin(*lst, s);
		if (!access(path, X_OK))
		{
			args->frist = path;
			return (1);
		}
		lst++;
	}
	return (0);
}
