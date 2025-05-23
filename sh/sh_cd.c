/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoussas <mhoussas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 11:02:48 by mhoussas          #+#    #+#             */
/*   Updated: 2025/05/22 21:44:42 by mhoussas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

static t_env	*find_virtual_pwd_env(void)
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

static void	update_virtual_pwd(char *aid)
{
	t_env	*node;

	node = find_virtual_pwd_env();
	if (getcwd(NULL, 0))
		node->value = ft_env_strdup(getcwd(NULL, 0));
	else
	{
		if (node->value[ft_strlen(node->value) - 1] != '/')
			aid = ft_strjoin("/", aid);
		node->value = ft_env_strdup(ft_strjoin(node->value, aid));
		ft_putendl_fd(ft_strjoin("cd: error retrieving current directory: ", \
			ft_strjoin("getcwd: cannot access parent directories: No such fil", \
				"e or directory")), 2);
	}
}

int	sh_cd(t_args *args)
{
	char	*target_path;

	if (!args->args || !*(args->args))
	{
		target_path = ft_getenv("HOME");
		if (!target_path)
			return (ft_print_error("cd", "HOME not set", "Nothing"), 1);
		else if (!*target_path)
			return (0);
	}
	else
		target_path = *(args->args);
	if (chdir(target_path))
		return (ft_print_error("cd", target_path, NULL), 1);
	update_virtual_pwd(target_path);
	return (0);
}
