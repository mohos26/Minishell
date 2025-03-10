/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_export_utlis.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoussas <mhoussas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 11:46:26 by mhoussas          #+#    #+#             */
/*   Updated: 2025/03/10 09:39:31 by mhoussas         ###   ########.fr       */
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

void	ft_add_var(char *var)
{
	char	**res;

	res = ft_export_split(var);
	ft_lstadd_back(ft_getenv(NULL), ft_lstnew(ft_local_strdup(res[0]),
			ft_local_strdup(res[1]), !!ft_strchr(var, '=')));
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
