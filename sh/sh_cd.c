/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoussas <mhoussas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 11:02:48 by mhoussas          #+#    #+#             */
/*   Updated: 2025/05/05 21:21:07 by mhoussas         ###   ########.fr       */
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

void	sh_cd(t_args *args)
{
	DIR		*ptr;
	char	*target_path;

	if (!args->args || !*(args->args))
	{
		target_path = ft_getenv("HOME");
		if (!target_path)
			return (ft_print_error("cd", "HOME not set", "Nothing"));
		else if (!*target_path)
			return ;
	}
	else
		target_path = *(args->args);
	ptr = opendir(target_path);
	if (ptr)
	{
		chdir(target_path);
		closedir(ptr);
	}
	else
		return (ft_print_error("cd", target_path, NULL));
	update_virtual_pwd(target_path);
}
