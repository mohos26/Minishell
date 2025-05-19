/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoussas <mhoussas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 10:18:17 by mhoussas          #+#    #+#             */
/*   Updated: 2025/05/19 09:27:39 by mhoussas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

volatile sig_atomic_t	g_last_signal_received;

void	ft_update_status(int status)
{
	t_env	*env;

	env = *ft_env(NULL);
	while (env)
	{
		if (!ft_strncmp(env->name, "?", INT_MAX))
			break ;
		env = env->next;
	}
	env->value = ft_env_strdup(ft_itoa(status));
}

int	main(int ac, char **av, char **env)
{
	char	*prompt;
	int		status;

	ft_init(env);
	while (ac || av)
	{
		g_last_signal_received = 0;
		prompt = readline("minishell$ ");
		if (g_last_signal_received == SIGINT)
			status = 1;
		if (!prompt)
		{
			ft_putendl_fd("exit", 2);
			break ;
		}
		else if (*prompt)
		{
			ft_update_status(ft_process_prompt(ft_init_prompt(prompt)));
			add_history(prompt);
		}
		ft_clean();
	}
	ft_exit(0);
}
