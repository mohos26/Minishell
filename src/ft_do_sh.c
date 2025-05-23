/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_do_sh.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoussas <mhoussas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 15:23:37 by mhoussas          #+#    #+#             */
/*   Updated: 2025/05/23 07:00:58 by mhoussas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	ft_do_sh(t_args *args)
{
	int	status;

	status = 0;
	if (!ft_strncmp(args->frist, "pwd", INT_MAX))
		status = sh_pwd();
	else if (!ft_strncmp(args->frist, "exit", INT_MAX))
		status = sh_exit(args);
	else if (!ft_strncmp(args->frist, "echo", INT_MAX))
		status = sh_echo(args);
	else if (!ft_strncmp(args->frist, "cd", INT_MAX))
		status = sh_cd(args);
	else if (!ft_strncmp(args->frist, "export", INT_MAX))
		status = sh_export(args);
	else if (!ft_strncmp(args->frist, "unset", INT_MAX))
		status = sh_unset(args);
	else if (!ft_strncmp(args->frist, "env", INT_MAX))
		status = sh_env();
	return (status);
}
