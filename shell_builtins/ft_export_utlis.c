/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export_utlis.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoussas <mhoussas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 11:46:26 by mhoussas          #+#    #+#             */
/*   Updated: 2025/02/23 11:31:35 by mhoussas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

char	**ft_export_split(char *s)
{
	char	*value;
	char	*name;
	int		len;
	char	**res;

	len = 0;
	while (s[len] && s[len] != '=')
		len++;
	name = ft_calloc(sizeof(char) * len + 1);
	ft_memcpy(name, s, len);
	name[len] = '\0';
	if (s[len])
		len++;
	value = ft_calloc(sizeof(char) * (ft_strlen(s) - len) + 1);
	ft_memcpy(value, s + len, ft_strlen(s) - len);
	value[ft_strlen(s) - len] = '\0';
	res = ft_calloc(sizeof(char *) * 2);
	res[0] = name;
	res[1] = value;
	return (res);
}

char	**ft_add_var(char **env, char *var)
{
	char	**res;
	int		len;
	int		i;

	len = 0;
	while (env && env[len])
		len++;
	res = ft_calloc(sizeof(char *) * (len + 1) + 1);
	i = 0;
	while (i < len)
		res[i++] = ft_strdup(*env++);
	res[len] = ft_strdup(var);
	res[len + 1] = NULL;
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

int	ft_is_onready(char **env, char *name)
{
	name = ft_strjoin(name, "=");
	while (env && *env)
	{
		if (!ft_strncmp(*env, name, ft_strlen(name))
			|| !ft_strncmp(*env, name, ft_strlen(*env)))
			return (1);
		env++;
	}
	return (0);
}
