/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export_utlis.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoussas <mhoussas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 11:46:26 by mhoussas          #+#    #+#             */
/*   Updated: 2025/02/22 12:14:21 by mhoussas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

static char	**ft_sort(char **lst)
{
	char	*tmp;
	int		len;
	int		i;
	int		j;

	len = 0;
	while (lst[len])
		len++;
	i = 0;
	while (lst[i + 1])
	{
		j = i + 1;
		while (lst[j])
		{
			if (ft_strncmp(lst[i], lst[j], INT_MAX) > 0)
			{
				tmp = lst[i];
				lst[i] = lst[j];
				lst[j] = tmp;
			}
			j++;
		}
		i++;
	}
	return (lst);
}

char	**ft_export_split(char *s)
{
	char	*value;
	char	*name;
	int		len;
	char	**res;

	len = 0;
	while (s[len] && s[len] != '=')
		len++;
	name = malloc(sizeof(char) * len + 1);
	ft_memcpy(name, s, len);
	name[len] = '\0';
	if (s[len])
		len++;
	value = malloc(sizeof(char) * (ft_strlen(s) - len) + 1);
	ft_memcpy(value, s + len, ft_strlen(s) - len);
	value[ft_strlen(s) - len] = '\0';
	res = malloc(sizeof(char *) * 2);
	res[0] = name;
	res[1] = value;
	return (res);
}

void	ft_print_env(char **env)
{
	char	**var;

	env = ft_sort(env);
	while (env && *env)
	{
		var = ft_export_split(*env);
		if (ft_strncmp(*var, "_", 2))
			printf("declare -x %s=\"%s\"\n", var[0], var[1]);
		env++;
	}
}

char	**ft_add_var(char **env, char *var)
{
	char	**res;
	int		len;
	int		i;

	len = 0;
	while (env[len])
		len++;
	res = malloc(sizeof(char *) * (len + 1) + 1);
	i = 0;
	while (i < len)
		res[i++] = ft_strdup(*env++);
	res[len] = ft_strdup(var);
	res[len + 1] = NULL;
	return (res);
}
