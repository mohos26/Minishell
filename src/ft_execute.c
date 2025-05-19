/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoussas <mhoussas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 09:03:46 by mhoussas          #+#    #+#             */
/*   Updated: 2025/05/19 09:30:07 by mhoussas         ###   ########.fr       */
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

char	**ft_convert_env(void)
{
	char	**head;
	char	*node;
	char	**res;
	t_env	*env;

	env = *ft_env(NULL);
	res = ft_calloc((ft_lstsize_env(env) + 1) * sizeof(char *));
	head = res;
	while (env)
	{
		if (env->active == 2)
		{
			env = env->next;
			continue ;
		}
		node = env->name;
		if (env->active)
			node = ft_strjoin(ft_strjoin(node, "="), env->value);
		*res++ = node;
		env = env->next;
	}
	*res = NULL;
	return (head);
}

int	ft_execute(t_args *args)
{
	char	**lst;
	pid_t	pid;
	int		status;

	lst = ft_create_lst(args->frist, args->args);
	pid = fork();
	if (!pid && execve(*lst, lst, ft_convert_env()) == -1)
	{
		perror("Execve failed");
		ft_exit(1);
	}
	wait(&status);
	return (status);
}
