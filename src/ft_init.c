/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoussas <mhoussas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 10:14:11 by mhoussas          #+#    #+#             */
/*   Updated: 2025/05/04 11:18:09 by mhoussas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

static void	ft_check_cwd(void)
{
	if (!getcwd(NULL, 0))
	{
		ft_print_error("init", ft_strjoin("error retrieving current directory:",
				" getcwd: cannot access parent directories"), NULL);
		ft_exit(1);
	}
}

void	ft_init(char **env)
{
	ft_check_cwd();
	ft_env(ft_build_env(env));
}
