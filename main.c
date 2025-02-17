/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoussas <mhoussas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 10:18:17 by mhoussas          #+#    #+#             */
/*   Updated: 2025/02/17 15:29:19 by mhoussas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int main()
{
	char	*s;

	while (1)
	{
		s = readline("-> ");
		if (!s)
			break ;
		else
		{
			printf("%s\n", s);
			printf("Is Valid: %d\n", ft_is_shell_command(ft_split(s, ' ')[0]));
			if (ft_is_shell_command(s))
				ft_do_shell_command(s);
		}
	}
}
