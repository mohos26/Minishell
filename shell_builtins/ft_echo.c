/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoussas <mhoussas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 08:42:53 by mhoussas          #+#    #+#             */
/*   Updated: 2025/02/23 11:25:31 by mhoussas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

static int	ft_len(char **lst)
{
	int	len;

	len = 0;
	while (lst && *lst)
	{
		len++;
		lst++;
	}
	return (len);
}

void	sh_echo(char **lst)
{
	int		sing;
	char	*res;

	sing = 1;
	if (!lst || !*lst)
	{
		printf("\n");
		return ;
	}
	if (!ft_strncmp(*lst, "-n", 3))
	{
		sing--;
		lst++;
	}
	res = NULL;
	while (*lst)
	{
		if (res)
			res = ft_strjoin(res, " ");
		res = ft_strjoin(res, *lst++);
	}
	if (res)
		printf("%s", res);
	if (sing)
		printf("\n");
}
