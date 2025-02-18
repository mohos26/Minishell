/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoussas <mhoussas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 10:18:17 by mhoussas          #+#    #+#             */
/*   Updated: 2025/02/18 12:55:25 by mhoussas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	main(void)
{
	char	**lst;
	char	*s;

	while (1)
	{
		s = readline("-> ");
		if (!s)
			break ;
		else if (*s)
		{
			lst = ft_split(s, ' ');
			printf("Is Valid: %d\n", ft_is_valid(*lst));
			if (ft_is_shell_command(*lst))
				ft_do_shell_command(lst);
		}
	}
}
