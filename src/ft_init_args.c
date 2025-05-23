/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoussas <mhoussas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 09:31:05 by mhoussas          #+#    #+#             */
/*   Updated: 2025/05/21 16:38:03 by mhoussas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

t_args	*ft_init_args(t_token *lst)
{
	t_args	*args;
	int		flag;

	flag = 0;
	args = ft_calloc(sizeof(t_args));
	args->frist = ft_extract_command(lst);
	args->args = ft_extract_args(lst);
	args->is_sh = ft_is_sh(args->frist);
	args->is_cmd = ft_is_execute(args);
	args->valid = args->is_cmd || args->is_sh;
	args->_redirections = ft_extract_redirections(lst, &flag);
	if (flag)
		return (NULL);
	return (args);
}
