/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoussas <mhoussas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 08:42:53 by mhoussas          #+#    #+#             */
/*   Updated: 2025/05/03 22:12:56 by mhoussas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

static char	*ft_aid(char **lst)
{
	char	*res;

	res = NULL;
	while (*lst)
	{
		if (res)
			res = ft_strjoin(res, " ");
		res = ft_strjoin(res, *lst++);
	}
	return (res);
}

void	sh_echo(t_args *args)
{
	int		sing;
	char	*aid;
	char	*res;
	char	**lst;

	sing = 1;
	lst = args->args;
	if (!lst || !*lst)
		return (ft_putstr_fd("\n", 1));
	if (!ft_strncmp(*lst, "-n", 2))
	{
		aid = (*lst) + 2;
		while (*aid == 'n')
			aid++;
		if (!*aid)
		{
			sing--;
			lst++;
		}
	}
	res = ft_aid(lst);
	if (sing)
		res = ft_strjoin(res, "\n");
	if (res)
		write(1, res, ft_strlen(res));
}
