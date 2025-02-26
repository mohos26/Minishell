/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoussas <mhoussas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 10:18:17 by mhoussas          #+#    #+#             */
/*   Updated: 2025/02/26 11:00:34 by mhoussas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	main(int ac, char **av, char **env)
{
	t_args	*args;
	char	*s;

	while (1)
	{
		s = readline("-> ");
		if (!s)
			break ;
		else if (*s)
		{
			args = ft_init(s, &env);
			if (!args->valid)
				ft_putstr_fd("No Valid\n", 2);
			if (args->is_sh)
				ft_do_sh(args);
			else if (args->is_cmd)
				ft_execute(args);
		}
	}
	ft_exit(0);
}
