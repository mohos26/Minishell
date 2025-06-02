/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoussas <mhoussas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 08:30:55 by mhoussas          #+#    #+#             */
/*   Updated: 2025/06/02 21:33:10 by mhoussas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

static int	ft_is_number_exit(char *s)
{
	unsigned long long	limit;
	int					sign;
	unsigned long long	n;

	while (*s == ' ')
		s++;
	sign = 0;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			sign = 1;
		s++;
	}
	if (!*s)
		return (0);
	limit = (unsigned long long)LLONG_MAX + sign;
	n = 0;
	while (*s && ft_isdigit(*s))
	{
		if (n > (limit - (*s - '0')) / 10)
			return (0);
		n = n * 10 + *s++ - '0';
	}
	return (*s == '\0');
}

int	sh_exit(t_args *args)
{
	int	status;

	status = ft_atoi(ft_getenv("?"));
	if (isatty(0) && isatty(1))
		ft_putstr_fd("exit\n", 2);
	if (args->args && *(args->args))
	{
		if (!ft_is_number_exit(*(args->args)))
		{
			status = 255;
			ft_print_error("exit", *(args->args), "numeric argument required");
		}
		else if (*(args->args + 1))
			return (ft_print_error("exit", "too many arguments", "Nothing"), 1);
		else
			status = ft_atoi(*(args->args));
	}
	ft_exit(status);
	return (0);
}
