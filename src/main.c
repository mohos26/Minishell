/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoussas <mhoussas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 10:18:17 by mhoussas          #+#    #+#             */
/*   Updated: 2025/06/15 18:19:15 by mhoussas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	main(int ac, char **av, char **env)
{
	char			*prompt;
	struct termios	term;

	ft_init(env);
	tcgetattr(STDIN_FILENO, &term);
	while (ac || av)
	{
		prompt = ft_strtrim(ft_readline("minishell$ "));
		if (g_last_signal_received == SIGINT)
			ft_update_status(1);
		g_last_signal_received = 0;
		if (!prompt)
		{
			ft_putendl_fd("exit", 2);
			break ;
		}
		else if (*prompt)
			ft_process_prompt(ft_init_prompt(prompt));
		tcsetattr(STDIN_FILENO, TCSANOW, &term);
		ft_clean();
	}
	ft_exit(ft_atoi(ft_getenv("?")));
}
