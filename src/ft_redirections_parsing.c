/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirections_parsing.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoussas <mhoussas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 11:43:28 by mhoussas          #+#    #+#             */
/*   Updated: 2025/05/03 14:43:57 by mhoussas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

/* ------------- Flags --------------
-- 0: No Redirections ---------------
-- 1: '<' Input Redirections --------
-- 2: '<' Output Redirections -------
-- 3: '>>' like '>' but he append ---
---------------------------------- */

int	ft_check_redirections(char **lst)
{
	while (lst && *lst && ft_strncmp(*lst, "<", 2) && ft_strncmp(*lst, ">", 2) \
			&& ft_strncmp(*lst, ">>", 3))
		lst++;
	if (*lst)
		return (!ft_strncmp(*lst, "<", 2) + !ft_strncmp(*lst, ">", 2) * 2 \
			+ 3 * !ft_strncmp(*lst, ">>", 3));
	return (0);
}

char	*ft_get_file(char **lst)
{
	while (lst && *lst && ft_strncmp(*lst, "<", 2) && ft_strncmp(*lst, ">", 2) \
		&& ft_strncmp(*lst, ">>", 3))
		lst++;
	if (*lst)
		return (*++lst);
	return (NULL);
}
