/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoussas <mhoussas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 09:31:05 by mhoussas          #+#    #+#             */
/*   Updated: 2025/04/16 16:19:01 by mhoussas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

char	*ft_aid(char **aid)
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

char	**ft_aid2(char **aid)
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
			return (aid + 1);
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
	return (args);
}
