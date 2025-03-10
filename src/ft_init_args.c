/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoussas <mhoussas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 09:31:05 by mhoussas          #+#    #+#             */
/*   Updated: 2025/03/10 08:09:48 by mhoussas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

t_args	*ft_init_args(char *s)
{
	t_args	*args;
	char	**aid;
	int		len;

	args = ft_calloc(sizeof(t_args));
	aid = ft_split(s, ' ');
	args->frist = *aid;
	args->args = aid + 1;
	args->is_sh = ft_is_sh(args->frist);
	args->is_cmd = ft_is_execute(args);
	args->valid = args->is_cmd || args->is_sh;
	args->redirections = ft_check_redirections(aid);
	if (args->redirections)
	{
		len = 0;
		while (args->args[len])
			len++;
		args->file_redirections = ft_get_file(aid);
		args->args[len - 2] = NULL;
	}
	return (args);
}
