/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoussas <mhoussas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 09:31:05 by mhoussas          #+#    #+#             */
/*   Updated: 2025/05/01 15:39:55 by mhoussas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

static char	*ft_aid(char **aid)
{
	while (*aid)
	{
		if (!ft_strncmp(*aid, "<", 2) || !ft_strncmp(*aid, ">", 2)
			|| !ft_strncmp(*aid, ">>", 2))
		{
			aid++;
			if (!*aid)
				break ;
		}
		else
			return (*aid);
		aid++;
	}
	return (NULL);
}

static char	**ft_aid2(char **aid)
{
	char	*s;

	s = NULL;
	while (*aid)
	{
		if (!ft_strncmp(*aid, "<", 2) || !ft_strncmp(*aid, ">", 2)
			|| !ft_strncmp(*aid, ">>", 2))
		{
			aid++;
			if (!*aid)
				break ;
		}
		else
			if (!s)
				s = ft_strjoin(s, " ");
			else
				s = ft_strjoin(ft_strjoin(s, " "), *aid);
		aid++;
	}
	return (ft_split(s, ' '));
}

static char	*ft_aid3(char **aid)
{
	while (*aid)
	{
		if (!ft_strncmp(*aid, "<", 2) || !ft_strncmp(*aid, ">", 2)
			|| !ft_strncmp(*aid, ">>", 2))
			return (*aid + 1);
		aid++;
	}
	return (NULL);
}

t_args	*ft_init_args(char *s)
{
	t_args	*args;
	char	**aid;

	args = ft_calloc(sizeof(t_args));
	aid = ft_split(s, ' ');
	args->frist = ft_aid(aid);
	args->args = ft_aid2(aid);
	args->is_sh = ft_is_sh(args->frist);
	args->is_cmd = ft_is_execute(args);
	args->valid = args->is_cmd || args->is_sh;
	args->redirections = ft_check_redirections(aid);
	if (args->redirections)
		args->file_redirections = ft_aid3(aid);
	return (args);
}
