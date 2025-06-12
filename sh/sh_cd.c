/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoussas <mhoussas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 11:02:48 by mhoussas          #+#    #+#             */
/*   Updated: 2025/06/12 18:32:27 by mhoussas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

static t_env	*ft_find_virtual_pwd_env(void)
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

static void	ft_update_virtual_pwd(char *aid)
{
	t_env	*node;
	char	*tmp;

	node = ft_find_virtual_pwd_env();
	tmp = node->value;
	if (ft_getcwd(NULL, 0))
		node->value = ft_env_strdup(ft_getcwd(NULL, 0));
	else
	{
		if (node->value[ft_strlen(node->value) - 1] != '/')
			aid = ft_strjoin("/", aid);
		node->value = ft_env_strdup(ft_strjoin(node->value, aid));
		ft_putendl_fd(ft_strjoin("cd: error retrieving current directory: ", \
			ft_strjoin("getcwd: cannot access parent directories: No such fil", \
				"e or directory")), 2);
	}
	free(tmp);
}

static char	*ft_get_parent_path(char *pwd)
{
	int	len;

	len = ft_strlen(pwd);
	while (len && pwd[len - 1] != '/')
		len--;
	pwd[len - 1] = '\0';
	return (ft_strdup(pwd));
}

static int	ft_attempt_virtual(char *target_path)
{
	char	*aid;
	char	**lst;

	if (target_path[0] == '/')
		return (0);
	lst = ft_split(target_path, '/');
	aid = ft_strdup(ft_getenv("1PWD"));
	while (lst && *lst)
	{
		if (ft_strncmp(*lst, ".", INT_MAX))
		{
			if (!ft_strncmp(*lst, "..", INT_MAX))
				aid = ft_get_parent_path(aid);
			else
				aid = ft_strjoin(aid, ft_strjoin("/", *lst));
			if (!ft_check_dir(aid))
				return (0);
		}
		lst++;
	}
	if (!ft_check_dir(aid))
		return (0);
	return (chdir(aid), 1);
}

int	sh_cd(t_args *args)
{
	DIR		*ptr;
	char	*target_path;

	if (!args->args || !*(args->args))
	{
		target_path = ft_getenv("HOME");
		printf("%s; %p\n", target_path, target_path);
		if (!target_path)
			return (ft_print_error("cd", "HOME not set", "Nothing"), 1);
		else if (!*target_path)
			return (0);
	}
	else
		target_path = *(args->args);
	ptr = opendir(target_path);
	if (ptr)
	{
		chdir(target_path);
		closedir(ptr);
	}
	else if (!(errno == 13 && ft_attempt_virtual(target_path)))
		return (ft_print_error("cd", target_path, NULL), 1);
	ft_update_virtual_pwd(target_path);
	return (0);
}
