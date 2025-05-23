/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_prompt.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoussas <mhoussas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 09:10:28 by mhoussas          #+#    #+#             */
/*   Updated: 2025/05/22 14:53:10 by mhoussas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	ft_process_prompt(t_prompt *prompt)
{
	if (!prompt)
	{
		if (!ft_atoi(ft_getenv("?")))
			ft_update_status(258);
		return ;
	}
	if (prompt->length == 1)
		ft_update_status(ft_process_command(*(prompt->args)));
	else
		ft_update_status(ft_handle_pipes(prompt));
}
