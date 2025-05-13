/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoussas <mhoussas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 06:18:14 by mhoussas          #+#    #+#             */
/*   Updated: 2025/05/13 10:11:32 by mhoussas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	**ft_append_array(char **lst, char *s)
{
	char	**res;
	int		len;

	len = 0;
	while (lst && lst[len])
		len++;
	res = calloc((len + 2),  sizeof(char*));
	len = 0;
	while (lst && lst[len])
	{
		res[len] = lst[len];
		len++;
	}
	res[len] = s;
	res[len+ 1] = NULL;
	return (res);
}

char	*ft_append_str(char	*s, char c)
{
	char	*res;
	int		i;

	i = 0;
	res = calloc((ft_strlen(s) + 2), sizeof(char));
	while (s && s[i])
	{
		res[i] = s[i];
		i++;
	}
	res[i++] = c;
	res[i] = '\0';
	return (res);
}

int	ft_is_space(char c)
{
	if (c == 32 || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

char	**ft_split_args(char *prompt)
{
	char	**lst;
	char	*aid;
	int		flag;

	flag = 0;
	lst = NULL;
	while (prompt && *prompt)
	{
		while (ft_is_space(*prompt))
			prompt++;
		aid = NULL;
		while (*prompt == '"' || *prompt == '\'' || (!ft_is_space(*prompt) && *prompt))
		{
			if (*prompt == '"' || *prompt == '\'')
			{
				if (*prompt++ == '"')
					while (*prompt != '"' && *prompt)
						aid = ft_append_str(aid, *prompt++);
				else
					while (*prompt != '\'' && *prompt)
						aid = ft_append_str(aid, *prompt++);
				if (*prompt)
					prompt++;
			}
			while (!ft_is_space(*prompt) && *prompt && *prompt != '"' && *prompt != '\'')
				aid = ft_append_str(aid, *prompt++);
		}
		if (aid)
			lst = ft_append_array(lst, aid);
	}
	return (lst);
}

int main()
{
	char	**lst;

	lst = ft_split_args(readline("-> "));
	while (lst && *lst)
	{
		puts(*lst++);
	}
}
