/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoussas <mhoussas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 10:18:17 by mhoussas          #+#    #+#             */
/*   Updated: 2025/03/10 12:42:07 by mhoussas         ###   ########.fr       */
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

static void	ft_process_prompt(t_prompt *prompt)
{
	t_args	**lst;
	pid_t	pid;

	lst = prompt->args;
	while (lst && *lst && prompt->length > 1)
	{
		pid = fork();
		if (!pid)
		{
			
			ft_process_command(*lst);
			ft_exit(0);
		}
		lst++;
	}
	while (waitpid(-1, NULL, 0) > 0)
		;
	if (prompt->length == 1)
		ft_process_command(*lst);
}

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
