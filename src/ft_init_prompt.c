/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_prompt.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoussas <mhoussas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 10:32:34 by mhoussas          #+#    #+#             */
/*   Updated: 2025/03/06 11:59:47 by mhoussas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

t_prompt	*ft_init_prompt(char *s, char ***env)
{
	t_prompt	*prompt;
	char		**lst;
	int			len;
	int			i;

	prompt = ft_calloc(sizeof(t_prompt));
	lst = ft_split(s, '|');
	len = 0;
	while (lst && lst[len])
		len++;
	prompt->length = len;
	prompt->args = ft_calloc(sizeof(t_args *) * len + 1);
	i = 0;
	while (lst && *lst)
		prompt->args[i++] = ft_init_args(*lst++, env);
	prompt->args[i] = NULL;
	prompt->valid = 1;
	return (prompt);
}
