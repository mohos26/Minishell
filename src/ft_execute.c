/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoussas <mhoussas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 09:03:46 by mhoussas          #+#    #+#             */
/*   Updated: 2025/06/01 16:01:28 by mhoussas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

static char	**ft_create_lst(char *frist, char **args)
{
	char	**head;
	char	**res;
	int		len;

	len = 0;
	while (args && args[len])
		len++;
	res = ft_calloc(sizeof(char *) * (len + 2));
	head = res;
	*res++ = frist;
	while (len--)
		*res++ = *args++;
	*res = NULL;
	return (head);
}

int	ft_execute(t_args *args)
{
	int		status;
	char	**lst;
	pid_t	pid;

	lst = ft_create_lst(args->frist, args->args);
	pid = fork();
	if (pid == -1)
		return (ft_print_error("fork", "Resource temporarily unavailable", \
				"Nothing"), 1);
	if (!pid)
	{
		signal(SIGINT, SIG_DFL);
		signal(SIGQUIT, SIG_DFL);
		execve(*lst, lst, ft_convert_env());
		perror("Execve failed");
		ft_exit(1);
	}
	wait(&status);
	return (status);
}
