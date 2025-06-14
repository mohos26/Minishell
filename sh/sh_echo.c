/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoussas <mhoussas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 08:42:53 by mhoussas          #+#    #+#             */
/*   Updated: 2025/06/14 15:51:02 by mhoussas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

static char	*ft_join_args_with_spaces(char **lst)
{
	char	*res;

	res = NULL;
	while (lst && *lst)
	{
		if (res)
			res = ft_strjoin(res, " ");
		res = ft_strjoin(res, *lst++);
	}
	return (res);
}

static int	ft_valid_flag(char *flag_suffix)
{
	while (*flag_suffix == 'n')
		flag_suffix++;
	return (!*flag_suffix);
}

int	sh_echo(t_args *args)
{
	char	**lst;
	int		sing;
	char	*res;

	sing = 1;
	lst = args->args;
	if (!lst || !*lst)
		return (ft_putendl_fd("", 1), 0);
	while (lst && *lst)
	{
		if (!ft_strncmp(*lst, "-n", 2) && ft_valid_flag(*lst + 2))
		{
			sing = 0;
			lst++;
		}
		else
			break ;
	}
	res = ft_join_args_with_spaces(lst);
	if (sing)
		res = ft_strjoin(res, "\n");
	if (res)
		ft_putstr_fd(res, 1);
	return (0);
}
