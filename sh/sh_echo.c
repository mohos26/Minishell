/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoussas <mhoussas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 08:42:53 by mhoussas          #+#    #+#             */
/*   Updated: 2025/05/04 22:36:48 by mhoussas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

static char	*ft_join_args_with_spaces(char **lst)
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

static int	ft_valid_flag(char *flag_suffix)
{
	while (*flag_suffix == 'n')
		flag_suffix++;
	return (!*flag_suffix);
}

void	sh_echo(t_args *args)
{
	char	**lst;
	int		sing;
	char	*res;

	sing = 1;
	lst = args->args;
	if (!lst || !*lst)
		return (ft_putstr_fd("\n", 1));
	while (1)
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
}
