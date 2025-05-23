/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoussas <mhoussas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 16:54:14 by mhoussas          #+#    #+#             */
/*   Updated: 2025/05/22 15:05:25 by mhoussas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	signal_handler(int sig)
{
	g_last_signal_received = sig;
	if (waitpid(-1, &sig, WNOHANG) == 0)
		return ;
	if (sig == SIGINT)
	{
		rl_replace_line("", 0);
		write (1, "\n", 1);
		rl_on_new_line();
		rl_redisplay();
	}
}

void	signal_util(void)
{
	printf("\r\033[K");
	rl_catch_signals = 0;
	signal(SIGINT, signal_handler);
	signal(SIGQUIT, signal_handler);
}

void	heredoc_signal(int sig)
{
	(void)sig;
	printf("\n");
	ft_exit(1);
}
