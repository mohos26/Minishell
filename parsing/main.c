/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoussas <mhoussas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 06:18:14 by mhoussas          #+#    #+#             */
/*   Updated: 2025/05/18 20:07:54 by mhoussas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

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

char	*ft_expand_quotes(char *var)
{
	var = ft_getenv(var);
	if (var)
		return (var);
	return ("");
}

char	*ft_expand_split(t_token **lst, char *aid, char *var)
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
		return (ft_strjoin(aid, aid2[len-1]));
	return (NULL);
}

int	ft_valid_quotes(char *s)
{
	while (*s)
	{
		if (*s == '"')
		{
			s++;
			s = ft_strchr(s, '"');
			if (!s)
				return (0);
		}
		else if (*s == '\'')
		{
			s++;
			s = ft_strchr(s, '\'');
			if (!s)
				return (0);
		}
		s++;
	}
	return (1);
}

char	*ft_aid2(char *prompt, char **aid, char *var)
{
	int		flag;

	flag = 0;
	if (*prompt == '$' && !flag)
		flag = 1;
	else if (flag && ft_is_valid(var, *prompt))
		var = ft_append_str(var, *prompt);
	else if (flag)
	{
		if (var)
			*aid = ft_strjoin(*aid, ft_expand_quotes(var));
		flag = 0;
		var = NULL;
		ft_aid2(prompt + 1, aid, var);
	}
	else
		*aid = ft_append_str(*aid, *prompt);
	return (var);
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
					*aid = ft_strjoin(*aid, ft_expand_quotes(var));
				flag = 0;
				var = NULL;
				prompt--;
			}
			else
				*aid = ft_append_str(*aid, *prompt);
			prompt++;
		}
		if (var)
			*aid = ft_strjoin(*aid, ft_expand_quotes(var));
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


t_token	*ft_split_args(char *prompt)
{
	t_token	*lst;
	char	*aid;
	char	*var;
	int		flag;
	int		flag2;

	lst = NULL;
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
						aid = ft_expand_split(&lst, aid, var);
					var = NULL;
					if (aid && *aid)
						ft_lstadd_back_token(&lst, ft_lstnew_token(aid, TOKEN_WORD));
					aid = NULL;
					flag2 = 0;
					ft_lstadd_back_token(&lst, ft_lstnew_token(ft_strdup("|"), TOKEN_PIPE));
				}
				else if (*prompt == '<')
				{
					if (var)
						aid = ft_expand_split(&lst, aid, var);
					var = NULL;
					if (aid && *aid)
						ft_lstadd_back_token(&lst, ft_lstnew_token(aid, TOKEN_WORD));
					aid = NULL;
					flag2 = 0;
					if (*(prompt + 1) == '<')
					{
						ft_lstadd_back_token(&lst, ft_lstnew_token(ft_strdup("<<"), TOKEN_HEREDOC));
						prompt++;
					}
					else
						ft_lstadd_back_token(&lst, ft_lstnew_token(ft_strdup("<"), TOKEN_RED_IN));
				}
				else if (*prompt == '>')
				{
					if (var)
						aid = ft_expand_split(&lst, aid, var);
					var = NULL;
					if (aid && *aid)
						ft_lstadd_back_token(&lst, ft_lstnew_token(aid, TOKEN_WORD));
					aid = NULL;
					flag2 = 0;
					if (*(prompt + 1) == '>')
					{
						ft_lstadd_back_token(&lst, ft_lstnew_token(ft_strdup(">>"), TOKEN_RED_APP));
						prompt++;
					}
					else
						ft_lstadd_back_token(&lst, ft_lstnew_token(ft_strdup(">"), TOKEN_RED_OUT));
				}
				else if (*prompt == '$' && !flag)
					flag = 1;
				else if (flag && ft_is_valid(var, *prompt))
					var = ft_append_str(var, *prompt);
				else if (flag)
				{
					if (var)
						aid = ft_expand_split(&lst, aid, var);
					aid = ft_append_str(aid, *prompt);
					flag = 0;
					var = NULL;
				}
				else
					aid = ft_append_str(aid, *prompt);
				prompt++;
			}
			if (var)
				aid = ft_expand_split(&lst, aid, var);
		}
		if (aid)
			ft_lstadd_back_token(&lst, ft_lstnew_token(aid, TOKEN_WORD));
	}
	return (lst);
}

int ft_syntax_error(t_token *tokens)
{
	t_token *temp;
	t_token *temp2;

	temp = tokens;
	if (temp && temp->type == TOKEN_PIPE)
	{
		printf("minishell$ syntax error near unexpected token\n");
		return (258);
	}
	while (temp)
	{
		if (temp->type == TOKEN_RED_APP)
		{
			temp2 = temp->next;
			if (!temp2 || temp2->type != TOKEN_WORD)
			{
				printf("minishell$ syntax error near unexpected token\n");
				return (258);
			}
		}
		if (temp->type == TOKEN_RED_IN)
		{
			t_token *temp2 = temp->next;
			if (!temp2 || temp2->type != TOKEN_WORD)
			{
				printf ("minishell$ syntax error near unexpected token\n");
				return (258);
			}
		}
		if (temp->type == TOKEN_RED_OUT)
		{
			t_token *temp2 = temp->next;
			if (!temp2 || temp2->type != TOKEN_WORD)
			{
				printf ("minishell$ syntax error near unexpected token\n");

				return (258);
			}
		}
		if (temp->type == TOKEN_HEREDOC)
		{
			t_token *temp2 = temp->next;
			if (!temp2 || temp2->type != TOKEN_WORD)
			{
				printf ("minishell$ syntax error near unexpected token\n");

				return (258);
			}
		}
		temp = temp->next;
	}
	temp2 = ft_lstlast_token(tokens);
	if (temp2 && temp2->type != TOKEN_WORD)
	{
		printf ("minishell$ syntax error near unexpected token\n");

		return (258);
	}
	return (0);
}

// int main()
// {
// 	t_token	*lst;

// 	while (1)
// 	{
// 		lst = ft_split_args(readline("-> "));
// 		if (ft_syntax_error(lst))
// 			continue;
// 		while (lst)
// 		{
// 			printf("%s; -> %d\n", lst->value, lst->type);
// 			lst = lst->next;
// 		}
// 	}
// }
