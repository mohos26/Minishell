/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_not_valid.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoussas <mhoussas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 13:38:29 by mhoussas          #+#    #+#             */
/*   Updated: 2025/06/04 13:38:54 by mhoussas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	ft_not_valid(t_args *args)
{
	int		status;
	char	*aid;

	status = 126;
	aid = args->frist;
	if (!ft_strlen(ft_getenv("PATH")))
		if (*aid && !ft_strchr(aid, '/'))
			aid = ft_strjoin("./", aid);
	if (!ft_strchr(aid, '/') && !args->is_cmd)
	{
		ft_print_error(args->frist, "command not found", "Nothing");
		status = 127;
	}
	else if (ft_check_dir(aid))
		ft_print_error(args->frist, "is a directory", "Nothing");
	else if (!access(aid, F_OK) && access(aid, X_OK))
		ft_print_error(args->frist, "Permission denied", "Nothing");
	else
	{
		if (errno == 2)
			status = 127;
		ft_print_error(args->frist, strerror(errno), "Nothing");
	}
	return (status);
}
