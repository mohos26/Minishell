/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoussas <mhoussas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 10:18:17 by mhoussas          #+#    #+#             */
/*   Updated: 2025/05/10 19:08:00 by mhoussas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	main(int ac, char **av, char **env)
{
	char	*prompt;
	int		status;

	ft_init(env);
	while (ac || av)
	{
		prompt = readline("-> ");
		if (!prompt)
			break ;
		else if (*prompt)
		{
			status = ft_process_prompt(ft_init_prompt(prompt));
			printf("+ staus: %d\n", status);
		}
		ft_clean();
	}
	ft_exit(0);
}
