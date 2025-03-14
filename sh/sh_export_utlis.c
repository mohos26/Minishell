/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_export_utlis.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoussas <mhoussas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 11:46:26 by mhoussas          #+#    #+#             */
/*   Updated: 2025/03/14 17:33:02 by mhoussas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

char	**ft_var_split(char *s)
{
	char	**res;
	int		len;

	len = 0;
	res = ft_calloc(sizeof(char *) * 2 + 1);
	res[0] = ft_calloc(sizeof(char) * len + 1);
	while (s[len] && s[len] != '=')
		len++;
	ft_memcpy(res[0], s, len);
	res[0][len] = '\0';
	if (s[len])
		len++;
	res[1] = ft_calloc(sizeof(char) * (ft_strlen(s) - len) + 1);
	ft_memcpy(res[1], s + len, ft_strlen(s) - len);
	res[1][ft_strlen(s) - len] = '\0';
	res[2] = NULL;
	return (res);
}

int	ft_valid_name(char *s)
{
	if (!ft_isalpha(*s) && *s != '_')
		return (0);
	s++;
	while (*s)
	{
		if (!ft_isalnum(*s) && *s != '_')
			return (0);
		s++;
	}
	return (1);
}

int	ft_is_onready(char *name)
{
	t_list	*env;

	env = *ft_getenv(NULL);
	name = ft_strjoin(name, "=");
	while (env)
	{
		if (!ft_strncmp(env->name, name, ft_strlen(name) + 1))
			return (1);
		env = env->next;
	}
	return (0);
}

int	ft_is_forbiden(char *name)
{
	return (!ft_strncmp("_", name, 2));
}
