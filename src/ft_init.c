/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoussas <mhoussas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 09:31:05 by mhoussas          #+#    #+#             */
/*   Updated: 2025/02/25 09:46:23 by mhoussas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

t_args	*ft_init(char *s, char ***env)
{
	t_args	*args;
	char	**aid;

	args = ft_calloc(sizeof(t_args));
	aid = ft_split(s, ' ');
	args->frist = *aid;
	args->args = aid + 1;
	args->env = env;
	args->is_cmd = ft_is_execute(args->frist);
	args->is_sh = ft_is_sh(args->frist);
	args->valid = args->is_cmd || args->is_sh;
	return (args);
}
