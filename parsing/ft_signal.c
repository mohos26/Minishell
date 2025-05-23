/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoussas <mhoussas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 10:03:48 by amaliari          #+#    #+#             */
/*   Updated: 2025/05/23 22:51:23 by mhoussas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	ft_signal_handler(int sig)
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

void	ft_signal_util(void)
{
	rl_catch_signals = 0;
	signal(SIGINT, ft_signal_handler);
	signal(SIGQUIT, ft_signal_handler);
}

void	ft_heredoc_signal(int sig)
{
	(void)sig;
	printf("\n");
	ft_exit(1);
}
