/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoussas <mhoussas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 10:18:17 by mhoussas          #+#    #+#             */
/*   Updated: 2025/04/30 16:26:04 by mhoussas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	main(int ac, char **av, char **env)
{
	char	*prompt;

	ft_init(env);
	while (ac || av)
	{
		prompt = readline("-> ");
		if (!prompt)
			break ;
		else if (*prompt)
			ft_process_prompt(ft_init_prompt(prompt));
		ft_clean();
	}
	ft_exit(0);
}
