/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_do_shell_command.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoussas <mhoussas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 15:23:37 by mhoussas          #+#    #+#             */
/*   Updated: 2025/02/23 09:49:13 by mhoussas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_do_shell_command(char **lst, char ***env)
{
	if (!ft_strncmp(*lst, "pwd", 4))
		sh_pwd();
	else if (!ft_strncmp(*lst, "exit", 5))
		sh_exit();
	else if (!ft_strncmp(*lst, "echo", 5))
		sh_echo(++lst);
	else if (!ft_strncmp(*lst, "cd", 3))
		sh_cd(*++lst);
	else if (!ft_strncmp(*lst, "export", 7))
		sh_export(++lst, env);
	else if (!ft_strncmp(*lst, "unset", 5))
		sh_unset(++lst, env);
	else if (!ft_strncmp(*lst, "env", 4))
		sh_env(*env);
}
