/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoussas <mhoussas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 10:18:17 by mhoussas          #+#    #+#             */
/*   Updated: 2025/03/05 15:14:41 by mhoussas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

static void	ft_process_command(t_args *args)
{
	if (!args->valid)
	{
		ft_putstr_fd("No Valid\n", 2);
		return ;
	}
	ft_do_redirection(args);
	if (args->is_sh)
		ft_do_sh(args);
	else if (args->is_cmd)
		ft_execute(args);
	ft_close_redirection(args);
}

int	main(int ac, char **av, char **env)
{
	char	*s;

	ac--;
	av++;
	ft_init(&env);
	while (1)
	{
		s = readline("-> ");
		if (!s)
			break ;
		else if (*s)
			ft_process_command(ft_init_args(s, &env));
	}
	ft_exit(0);
}
