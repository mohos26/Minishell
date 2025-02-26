/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoussas <mhoussas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 11:02:48 by mhoussas          #+#    #+#             */
/*   Updated: 2025/02/25 12:43:27 by mhoussas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

static void	ft_local_print_error(void)
{
	ft_putstr_fd("Minishell: cd: HOME not set\n", 2);
}

char	*ft_get_home(char **env)
{
	while (env && *env)
	{
		if (!ft_strncmp(*env, "HOME=", 5))
			return (*env + 5);
		env++;
	}
	return (NULL);
}

void	sh_cd(t_args *args)
{
	DIR		*ptr;
	char	*aid;

	if (!args->args || !*(args->args))
	{
		aid = ft_get_home(*(args->env));
		if (!aid)
			return (ft_local_print_error());
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
		ft_print_error("cd", aid, NULL);
}
