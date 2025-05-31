/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_prompt.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoussas <mhoussas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 09:10:28 by mhoussas          #+#    #+#             */
/*   Updated: 2025/05/27 09:44:12 by mhoussas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	ft_process_prompt(t_prompt *prompt)
{
	int	status;

	if (!prompt)
	{
		if (!ft_atoi(ft_getenv("?")))
			ft_update_status(258);
		return ;
	}
	if (prompt->length == 1)
		status = ft_process_command(*(prompt->args));
	else
		status = ft_handle_pipes(prompt);
	ft_update_status(status);
}
