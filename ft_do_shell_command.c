/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_do_shell_command.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoussas <mhoussas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 15:23:37 by mhoussas          #+#    #+#             */
/*   Updated: 2025/02/22 18:26:53 by mhoussas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_do_shell_command(char **lst, char ***env)
{
	if (!ft_strncmp(*lst, "pwd", 4))
		ft_pwd();
	else if (!ft_strncmp(*lst, "exit", 5))
		ft_exit();
	else if (!ft_strncmp(*lst, "echo", 5))
		ft_echo(++lst);
	else if (!ft_strncmp(*lst, "cd", 3))
		ft_cd(*++lst);
	else if (!ft_strncmp(*lst, "export", 7))
		ft_export(++lst, env);
	else if (!ft_strncmp(*lst, "unset", 5))
		ft_unset(++lst, env);
}
