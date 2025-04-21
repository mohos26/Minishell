/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wildcard.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoussas <mhoussas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 18:21:22 by mhoussas          #+#    #+#             */
/*   Updated: 2025/04/19 19:48:02 by mhoussas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

static int	ft_count_visible_files(void)
{
	DIR				*dir;
	struct dirent	*ptr;
	int				len;

	len = 0;
	dir = opendir(".");
	ptr = readdir(dir);
	while (ptr)
	{
		if (*(ptr->d_name) != '.')
			len++;
		ptr = readdir(dir);
	}
	closedir(dir);
	return (len);
}

static char	*ft_simplify_wildcard(char *s)
{
	char	*res;
	int		flag;
	int		i;
	int		j;

	i = 0;
	j = 0;
	flag = 1;
	res = calloc(strlen(s) + 1, sizeof(char));
	while (s && s[i])
	{
		if (s[i] != '*')
		{
			res[j++] = s[i];
			flag = 1;
		}
		else if (flag)
		{
			res[j++] = s[i];
			flag = 0;
		}
		i++;
	}
	res[j] = '\0';
	return (res);
}

static int	ft_match_wildcard(char *pattern, char *filename)
{
	while (*pattern)
	{
		if (*pattern == '*')
		{
			filename = strchr(filename, *++pattern);
			if (!filename || !*filename)
				break ;
		}
		else if (*pattern != *filename)
			break ;
		pattern++;
		filename++;
	}
	return (!*pattern);
}

static char	**ft_get_files(void)
{
	char			**lst;
	struct dirent	*ptr;
	DIR				*dir;
	int				len;
	int				i;

	i = 0;
	len = ft_count_visible_files();
	dir = opendir(".");
	ptr = readdir(dir);
	lst = calloc(len + 1, sizeof(char *));
	while (i < len)
	{
		if (*(ptr->d_name) != '.')
			lst[i++] = ptr->d_name;
		ptr = readdir(dir);
	}
	lst[i] = NULL;
	closedir(dir);
	return (lst);
}

char	**ft_wildcard(char *s)
{
	char	*pattern;
	char	**res;
	char	**lst;
	int		len;
	int		i;

	len = 0;
	pattern = ft_simplify_wildcard(s);
	lst = ft_get_files();
	while (lst && *lst)
		if (ft_match_wildcard(pattern, *lst++))
			len++;
	i = 0;
	res = calloc(len + 1, sizeof(char *));
	lst = ft_get_files();
	while (lst && *lst)
	{
		if (ft_match_wildcard(pattern, *lst))
			res[i++] = *lst;
		lst++;
	}
	res[i] = NULL;
	return (res);
}


int main()
{
	char **lst = ft_wildcard("***********ft**********.***********c************");
	while (lst && *lst)
		puts(*lst++);
}