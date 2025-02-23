/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoussas <mhoussas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 14:36:54 by mhoussas          #+#    #+#             */
/*   Updated: 2025/02/23 11:31:02 by mhoussas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static char	**ft_create_lst(void)
{
	char	**lst;
	int		n;

	n = 7;
	lst = ft_calloc(n * sizeof(char *) + 1);
	lst[0] = ft_strdup("pwd");
	lst[1] = ft_strdup("exit");
	lst[2] = ft_strdup("echo");
	lst[3] = ft_strdup("cd");
	lst[4] = ft_strdup("export");
	lst[5] = ft_strdup("unset");
	lst[6] = ft_strdup("env");
	lst[n] = NULL;
	return (lst);
}

int	ft_is_shell_command(char *s)
{
	char	**lst;

	lst = ft_create_lst();
	while (*lst)
	{
		if (s && !ft_strncmp(*lst, s, ft_strlen(s)))
			return (1);
		lst++;
	}
	return (0);
}

int	ft_is_valid(char *s)
{
	return (ft_is_shell_command(s) || ft_is_execute(s));
}
