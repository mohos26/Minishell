/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoussas <mhoussas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 10:18:17 by mhoussas          #+#    #+#             */
/*   Updated: 2025/02/25 10:15:58 by mhoussas         ###   ########.fr       */
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
			printf("Valid: %d\n", args->valid);
			if (args->is_sh)
				ft_do_shell_command(args);
		}
	}
	ft_exit(0);
}
