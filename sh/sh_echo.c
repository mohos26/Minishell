/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoussas <mhoussas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 08:42:53 by mhoussas          #+#    #+#             */
/*   Updated: 2025/02/25 10:19:15 by mhoussas         ###   ########.fr       */
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

char	*ft_aid(char **lst)
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
	char	*res;
	char	**lst;

	sing = 1;
	lst = args->args;
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
	res = ft_aid(lst);
	if (res)
		printf("%s", res);
	if (sing)
		printf("\n");
}
