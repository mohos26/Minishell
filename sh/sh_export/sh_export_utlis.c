/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_export_utlis.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoussas <mhoussas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 11:46:26 by mhoussas          #+#    #+#             */
/*   Updated: 2025/05/23 07:00:16 by mhoussas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

char	**ft_var_split(char *s)
{
	int		val_len;
	int		key_len;
	char	**res;
	int		i;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != '=')
		i++;
	key_len = i;
	val_len = 0;
	if (s[i] == '=')
		val_len = ft_strlen(s + i + 1);
	res = ft_calloc(3 * sizeof(char *));
	res[0] = ft_calloc((key_len + 1) * sizeof(char));
	ft_memcpy(res[0], s, key_len);
	res[1] = NULL;
	if (s[i] == '=')
	{
		res[1] = ft_calloc((val_len + 1) * sizeof(char));
		ft_memcpy(res[1], s + i + 1, val_len);
	}
	res[2] = NULL;
	return (res);
}

int	ft_valid_name(char *s)
{
	if (!ft_isalpha(*s))
		return (0);
	s++;
	while (*s)
	{
		if (!ft_isalnum(*s))
			return (0);
		s++;
	}
	return (1);
}

int	ft_is_onready(char *name)
{
	t_env	*env;

	env = *ft_env(NULL);
	while (env)
	{
		if (!ft_strncmp(env->name, name, INT_MAX))
			return (1);
		env = env->next;
	}
	return (0);
}

char	**ft_sort(void)
{
	char	**lst;
	char	*tmp;
	int		i;
	int		j;

	i = 0;
	lst = ft_convert_env();
	while (lst && *lst && lst[i + 1])
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
