/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoussas <mhoussas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 06:18:14 by mhoussas          #+#    #+#             */
/*   Updated: 2025/05/14 21:37:10 by mhoussas         ###   ########.fr       */
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

int	ft_is_valid(char *s, char c)
{
	if (!ft_strlen(s) && (c == '?' || ft_isalpha(c) || c == '_'))
		return (1);
	else if ((ft_isalnum(c) || c == '_') && *s != '?')
		return (1);
	return (0);
}

char	*ft_expand(char *s)
{
	return (ft_strjoin(ft_strjoin("{", s), "}"));
}

char	*ft_aid(char *prompt, char **aid)
{
	char	*var;
	int		flag;

	var = NULL;
	flag = 0;
	if (*prompt == '"')
	{
		prompt++;
		while (*prompt != '"' && *prompt)
		{
			if (*prompt == '$' && !flag)
				flag = 1;
			else if (flag && ft_is_valid(var, *prompt))
				var = ft_append_str(var, *prompt);
			else if (flag)
			{
				if (var)
					*aid = ft_strjoin(*aid, ft_expand(var));
				flag = 0;
				var = NULL;
				prompt--;
			}
			else
				*aid = ft_append_str(*aid, *prompt);
			prompt++;
		}
		if (var)
			*aid = ft_strjoin(*aid, ft_expand(var));
	}
	else if (*prompt == '\'')
	{
		prompt++;
		while (*prompt != '\'' && *prompt)
			*aid = ft_append_str(*aid, *prompt++);
	}
	if (*prompt == '"' || *prompt == '\'')
		prompt++;
	return (prompt);
}

char	**ft_split_args(char *prompt)
{
	char	**lst;
	char	*aid;
	char	*var;
	int		flag;
	int		flag2;

	lst = NULL;
	return NULL;
	while (prompt && *prompt)
	{
		while (ft_is_space(*prompt))
			prompt++;
		aid = NULL;
		flag2 = 1;
		while (flag2 && (*prompt == '"' || *prompt == '\'' || (!ft_is_space(*prompt) && *prompt)))
		{
			prompt = ft_aid(prompt, &aid);
			var = NULL;
			flag = 0;
			while (flag2 && !ft_is_space(*prompt) && *prompt && *prompt != '"' && *prompt != '\'')
			{
				if (*prompt == '|')
				{
					if (var)
						aid = ft_strjoin(aid, ft_expand(var));
					var = NULL;
					if (aid)
						lst = ft_append_array(lst, aid);
					aid = NULL;
					flag2 = 0;
					lst = ft_append_array(lst, ft_strdup("|"));
				}
				else if (*prompt == '<')
				{
					if (var)
						aid = ft_strjoin(aid, ft_expand(var));
					var = NULL;
					if (aid)
						lst = ft_append_array(lst, aid);
					aid = NULL;
					flag2 = 0;
					if (*(prompt + 1) == '<')
					{
						lst = ft_append_array(lst, ft_strdup("<<"));
						prompt++;
					}
					else
						lst = ft_append_array(lst, ft_strdup("<"));
				}
				else if (*prompt == '>')
				{
					if (var)
						aid = ft_strjoin(aid, ft_expand(var));
					var = NULL;
					if (aid)
						lst = ft_append_array(lst, aid);
					aid = NULL;
					flag2 = 0;
					if (*(prompt + 1) == '>')
					{
						lst = ft_append_array(lst, ft_strdup(">>"));
						prompt++;
					}
					else
						lst = ft_append_array(lst, ft_strdup(">"));
				}
				else if (*prompt == '$' && !flag)
					flag = 1;
				else if (flag && ft_is_valid(var, *prompt))
					var = ft_append_str(var, *prompt);
				else if (flag)
				{
					if (var)
						aid = ft_strjoin(aid, ft_expand(var));
					aid = ft_append_str(aid, *prompt);
					flag = 0;
					var = NULL;
				}
				else
					aid = ft_append_str(aid, *prompt);
				prompt++;
			}
			if (var)
				aid = ft_strjoin(aid, ft_expand(var));
		}
		if (aid)
			lst = ft_append_array(lst, aid);
	}
	return (lst);
}

int main()
{
	char	**lst;

	while (1)
	{
		lst = ft_split_args(readline("-> "));
		while (lst && *lst)
		{
			puts(*lst++);
		}
	}
}
