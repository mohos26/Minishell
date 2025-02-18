/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoussas <mhoussas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 11:11:37 by mhoussas          #+#    #+#             */
/*   Updated: 2025/02/18 11:25:32 by mhoussas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_print_error(char *command_name, char *arg)
{
	char	*s;

	s = ft_strjoin("Minishell: ", command_name);
	s = ft_strjoin(s, ": ");
	s = ft_strjoin(s, arg);
	perror(s);
}
