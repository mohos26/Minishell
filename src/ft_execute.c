/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoussas <mhoussas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 09:03:46 by mhoussas          #+#    #+#             */
/*   Updated: 2025/03/07 09:31:08 by mhoussas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

static char	**ft_create_lst(char *frist, char **args)
{
	char	**head;
	char	**res;
	int		len;

	len = 0;
	while (args[len])
		len++;
	res = ft_calloc(sizeof(char *) * (len + 1));
	head = res;
	*res++ = frist;
	while (len--)
		*res++ = *args++;
	*res = NULL;
	return (head);
}

void	ft_execute(t_args *args)
{
	char	**lst;
	pid_t	pid;

	lst = ft_create_lst(args->frist, args->args);
	pid = ft_fork();
	if (!pid && execve(*lst, lst, *(args->env)) == -1)
	{
		perror("Execve failed");
		ft_exit(1);
	}
	wait(NULL);
}
