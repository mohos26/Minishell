/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoussas <mhoussas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 11:11:37 by mhoussas          #+#    #+#             */
/*   Updated: 2025/06/14 15:52:08 by mhoussas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

/* -----------------------------------
--- is full: he write arg2 -----------
--- Noting:  he do Nothing -----------
--- NULL:    he use perror -----------
----------------------------------- */

void	ft_print_error(char *command_name, char *arg, char *arg2)
{
	char	*s;

	s = ft_strjoin("Minishell: ", command_name);
	s = ft_strjoin(s, ": ");
	s = ft_strjoin(s, arg);
	if (arg2 && !ft_strncmp(arg2, "Nothing", INT_MAX))
		ft_putendl_fd(s, 2);
	else if (arg2)
	{
		ft_putstr_fd(s, 2);
		ft_putstr_fd(": ", 2);
		ft_putendl_fd(arg2, 2);
	}
	else
		perror(s);
}
