/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoussas <mhoussas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 11:02:48 by mhoussas          #+#    #+#             */
/*   Updated: 2025/05/03 16:22:37 by mhoussas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

static t_env	*ft_aid2(void)
{
	t_env	*env;

	env = *ft_env(NULL);
	while (env)
	{
		if (!ft_strncmp(env->name, "1PWD", INT_MAX))
			break ;
		env = env->next;
	}
	return (env);
}

static void	ft_aid(char *aid)
{
	t_env	*node;

	node = ft_aid2();
	if (getcwd(NULL, 0))
		node->value = ft_env_strdup(getcwd(NULL, 0));
	else
		node->value = ft_env_strdup(ft_strjoin(ft_strjoin(node->value, "/"), \
			aid));
}

void	sh_cd(t_args *args)
{
	DIR		*ptr;
	char	*aid;

	if (!args->args || !*(args->args))
	{
		aid = ft_getenv("HOME");
		if (!aid)
			return (ft_print_error("cd", "HOME not set", "Nothing"));
		else if (!*aid)
			return ;
	}
	else
		aid = *(args->args);
	ptr = opendir(aid);
	if (ptr)
	{
		chdir(aid);
		closedir(ptr);
	}
	else
		return (ft_print_error("cd", aid, NULL));
	ft_aid(aid);
}
