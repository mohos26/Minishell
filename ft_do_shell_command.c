/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_do_shell_command.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoussas <mhoussas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 15:23:37 by mhoussas          #+#    #+#             */
/*   Updated: 2025/02/18 11:48:09 by mhoussas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_do_shell_command(char **lst)
{
	if (!ft_strncmp(*lst, "pwd", 4))
		ft_pwd();
	else if (!ft_strncmp(*lst, "exit", 5))
		ft_exit();
	else if (!ft_strncmp(*lst, "echo", 5))
		ft_echo(++lst);
	else if (!ft_strncmp(*lst, "cd", 3))
		ft_cd(*++lst);
}
