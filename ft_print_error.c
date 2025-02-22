/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoussas <mhoussas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 11:11:37 by mhoussas          #+#    #+#             */
/*   Updated: 2025/02/22 12:10:33 by mhoussas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_print_error(char *command_name, char *arg, char *arg2)
{
	char	*s;

	s = ft_strjoin("Minishell: ", command_name);
	s = ft_strjoin(s, ": ");
	s = ft_strjoin(s, arg);
	if (arg2)
	{
		ft_putstr_fd(s, 2);
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(arg2, 2);
		ft_putstr_fd("\n", 2);
	}
	else
		perror(s);
}
