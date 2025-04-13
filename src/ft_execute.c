/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoussas <mhoussas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 09:03:46 by mhoussas          #+#    #+#             */
/*   Updated: 2025/04/13 15:15:59 by mhoussas         ###   ########.fr       */
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
	res = ft_calloc(sizeof(char *) * (len + 2));
	head = res;
	*res++ = frist;
	while (len--)
		*res++ = *args++;
	*res = NULL;
	return (head);
}

char	**ft_convert_env(void)
{
	char	**head;
	char	**res;
	t_list	*env;
	char	*aid;

	env = *ft_env(NULL);
	res = ft_calloc(ft_lstsize(env) * sizeof(char *) + 1);
	head = res;
	while (env)
	{
		aid = env->name;
		if (env->active)
		{
			aid = ft_strjoin(aid, "=");
			aid = ft_strjoin(aid, env->value);
		}
		*res++ = aid;
		env = env->next;
	}
	*res = NULL;
	return (head);
}

void	ft_execute(t_args *args)
{
	char	**lst;
	pid_t	pid;

	pid = ft_fork();
	lst = ft_create_lst(args->frist, args->args);
	if (!pid && execve(*lst, lst, ft_convert_env()) == -1)
	{
		perror("Execve failed");
		ft_exit(1);
	}
	wait(NULL);
}
