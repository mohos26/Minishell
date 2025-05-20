/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoussas <mhoussas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 06:18:14 by mhoussas          #+#    #+#             */
/*   Updated: 2025/05/20 16:30:22 by mhoussas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

static int	ft_is_space(char c)
{
	if (c == 32 || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

static int	ft_is_valid(char *s, char c)
{
	if (!ft_strlen(s) && (c == '?' || ft_isalpha(c) || c == '_'))
		return (1);
	else if ((ft_isalnum(c) || c == '_') && *s != '?')
		return (1);
	return (0);
}

static char	*ft_expand_quotes(char *var)
{
	var = ft_getenv(var);
	if (var)
		return (var);
	return ("");
}

static char	*ft_expand_split(t_token **lst, char *aid, char *var)
{
	char	**aid2;
	int		len;
	int		i;

	len = 0;
	aid2 = ft_split(ft_getenv(var), ' ');
	while (aid2 && aid2[len])
		len++;
	i = 0;
	while (i < len -1)
	{
		ft_lstadd_back_token(lst, ft_lstnew_token(ft_strjoin(aid, aid2[i]), 0));
		aid = NULL;
		i++;
	}
	if (len)
		return (ft_strjoin(aid, aid2[len - 1]));
	return (NULL);
}

static char	*ft_aid4(char *prompt, char **aid)
{
	prompt++;
	while (*prompt != '\'' && *prompt)
		*aid = ft_append_str(*aid, *prompt++);
	return (prompt);
}

static char	*ft_aid5(char *prompt, char **aid)
{
	if (*prompt == '"' || *prompt == '\'')
	{
		if (!*aid)
			*aid = ft_strdup("");
		prompt++;
	}
	return (prompt);
}

static char	*ft_aid6(char *prompt, char **aid, char **var, int *flag)
{
	if (*var)
		*aid = ft_strjoin(*aid, ft_expand_quotes(*var));
	*flag = 0;
	*var = NULL;
	return (--prompt);
}

static char	*ft_aid(char *prompt, char **aid)
{
	char	*var;
	int		flag;

	flag = 0;
	var = NULL;
	if (*prompt++ == '"')
	{
		while (*prompt != '"' && *prompt)
		{
			if (*prompt == '$' && !flag)
				flag = 1;
			else if (flag && ft_is_valid(var, *prompt))
				var = ft_append_str(var, *prompt);
			else if (flag)
				prompt = ft_aid6(prompt, aid, &var, &flag);
			else
				*aid = ft_append_str(*aid, *prompt);
			prompt++;
		}
		if (var)
			*aid = ft_strjoin(*aid, ft_expand_quotes(var));
	}
	else if (*--prompt == '\'')
		prompt = ft_aid4(prompt, aid);
	return (ft_aid5(prompt, aid));
}

static char	*ft_aid2(t_token **lst, char *prompt)
{
	if (*prompt == '<' && *(prompt + 1) == '<')
	{
		ft_lstadd_back_token(lst, ft_lstnew_token(ft_strdup("<<"),
				TOKEN_HEREDOC));
		prompt++;
	}
	else if (*prompt == '>' && *(prompt + 1) == '>')
	{
		ft_lstadd_back_token(lst, ft_lstnew_token(ft_strdup(">>"),
				TOKEN_RED_APP));
		prompt++;
	}
	else if (*prompt == '>')
		ft_lstadd_back_token(lst, ft_lstnew_token(ft_strdup(">"),
				TOKEN_RED_OUT));
	else if (*prompt == '<')
		ft_lstadd_back_token(lst, ft_lstnew_token(ft_strdup("<"),
				TOKEN_RED_IN));
	else
		ft_lstadd_back_token(lst, ft_lstnew_token(ft_strdup("|"),
				TOKEN_PIPE));
	return (prompt);
}

static int	ft_rest(t_token **lst, char **aid, char **var)
{
	if (*var)
		*aid = ft_expand_split(lst, *aid, *var);
	*var = NULL;
	if (*aid && **aid)
		ft_lstadd_back_token(lst, ft_lstnew_token(*aid, TOKEN_WORD));
	*aid = NULL;
	return (0);
}

static int	ft_aid7(t_token **lst, char **aid, char **var, char c)
{
	if (*var)
		*aid = ft_expand_split(lst, *aid, *var);
	*aid = ft_append_str(*aid, c);
	var = NULL;
	return (0);
}

static int	ft_aid3(t_token **lst, char **s, char **aid, int flag2)
{
	char	*var;
	int		flag;

	flag = 0;
	var = NULL;
	while (flag2 && !ft_is_space(**s) && **s && **s != '"' && **s != '\'')
	{
		if (**s == '|' || **s == '<' || **s == '>')
		{
			flag2 = ft_rest(lst, aid, &var);
			*s = ft_aid2(lst, *s);
		}
		else if (**s == '$' && !flag)
			flag = 1;
		else if (flag && ft_is_valid(var, **s))
			var = ft_append_str(var, **s);
		else if (flag)
			flag = ft_aid7(lst, aid, &var, **s);
		else
			*aid = ft_append_str(*aid, **s);
		(*s)++;
	}
	if (var)
		*aid = ft_expand_split(lst, *aid, var);
	return (flag2);
}

t_token	*ft_split_args(char *prompt)
{
	t_token	*lst;
	char	*aid;
	int		flag2;

	lst = NULL;
	while (prompt && *prompt)
	{
		while (ft_is_space(*prompt))
			prompt++;
		aid = NULL;
		flag2 = 1;
		while (flag2 && (*prompt == '"' || *prompt == '\''
				|| (!ft_is_space(*prompt) && *prompt)))
		{
			prompt = ft_aid(prompt, &aid);
			flag2 = ft_aid3(&lst, &prompt, &aid, flag2);
		}
		if (aid)
			ft_lstadd_back_token(&lst, ft_lstnew_token(aid, TOKEN_WORD));
	}
	return (lst);
}
