/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_do_shell_command.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoussas <mhoussas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 15:23:37 by mhoussas          #+#    #+#             */
/*   Updated: 2025/02/25 09:48:47 by mhoussas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	ft_do_shell_command(t_args *args)
{
	if (!ft_strncmp(args->frist, "pwd", 4))
		sh_pwd();
	else if (!ft_strncmp(args->frist, "exit", 5))
		sh_exit();
	else if (!ft_strncmp(args->frist, "echo", 5))
		sh_echo(args);
	else if (!ft_strncmp(args->frist, "cd", 3))
		sh_cd(args);
	else if (!ft_strncmp(args->frist, "export", 7))
		sh_export(args);
	else if (!ft_strncmp(args->frist, "unset", 5))
		sh_unset(args);
	else if (!ft_strncmp(args->frist, "env", 4))
		sh_env(args);
}
