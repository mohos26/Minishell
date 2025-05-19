/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_do_sh.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoussas <mhoussas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 15:23:37 by mhoussas          #+#    #+#             */
/*   Updated: 2025/05/19 09:48:10 by mhoussas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	ft_do_sh(t_args *args)
{
	if (!ft_strncmp(args->frist, "pwd", INT_MAX))
		sh_pwd();
	else if (!ft_strncmp(args->frist, "exit", INT_MAX))
		sh_exit(args);
	else if (!ft_strncmp(args->frist, "echo", INT_MAX))
		sh_echo(args);
	else if (!ft_strncmp(args->frist, "cd", INT_MAX))
		sh_cd(args);
	else if (!ft_strncmp(args->frist, "export", INT_MAX))
		sh_export(args);
	else if (!ft_strncmp(args->frist, "unset", INT_MAX))
		sh_unset(args);
	else if (!ft_strncmp(args->frist, "env", INT_MAX))
		sh_env();
	return (0);
}
