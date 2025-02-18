/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoussas <mhoussas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 14:36:54 by mhoussas          #+#    #+#             */
/*   Updated: 2025/02/18 11:52:00 by mhoussas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static char	**ft_create_lst(void)
{
	char	**lst;
	int		n;

	n = 4;
	lst = malloc(n * sizeof(char *) + 1);
	if (!lst)
		return (NULL);
	lst[0] = ft_strdup("pwd");
	lst[1] = ft_strdup("exit");
	lst[2] = ft_strdup("echo");
	lst[3] = ft_strdup("cd");
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
