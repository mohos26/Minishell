/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_execute.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoussas <mhoussas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 15:00:29 by mhoussas          #+#    #+#             */
/*   Updated: 2025/02/24 16:40:58 by mhoussas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	ft_is_execute(char *s)
{
	char	**lst;

	if (ft_strchr(s, '/'))
		return (!access(s, X_OK));
	lst = ft_split(getenv("PATH"), ':');
	s = ft_strjoin("/", s);
	while (lst && *lst)
	{
		if (!access(ft_strjoin(*lst, s), X_OK))
			return (1);
		lst++;
	}
	return (0);
}
