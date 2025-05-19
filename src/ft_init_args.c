/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoussas <mhoussas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 09:31:05 by mhoussas          #+#    #+#             */
/*   Updated: 2025/05/19 09:54:44 by mhoussas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

static char	**ft_append_array(char **lst, char *s)
{
	char	**res;
	int		len;

	len = 0;
	while (lst && lst[len])
		len++;
	res = ft_calloc((len + 2) * sizeof(char *));
	len = 0;
	while (lst && lst[len])
	{
		res[len] = lst[len];
		len++;
	}
	res[len] = s;
	res[len + 1] = NULL;
	return (res);
}

static char	*ft_extract_command(t_token *lst)
{
	while (lst)
	{
		if (lst->type == TOKEN_PIPE)
			break ;
		else if (lst->type == TOKEN_RED_IN || lst->type == TOKEN_RED_OUT
			|| lst->type == TOKEN_RED_APP || lst->type == TOKEN_HEREDOC)
			lst = lst->next;
		else if (lst->type == TOKEN_WORD)
			return (lst->value);
		if (lst)
			lst = lst->next;
	}
	return (NULL);
}

static char	**ft_extract_args(t_token *lst)
{
	char	**res;
	int		flag;

	flag = 0;
	res = NULL;
	while (lst)
	{
		if (lst->type == TOKEN_PIPE)
			break ;
		else if (lst->type == TOKEN_WORD && flag)
			res = ft_append_array(res, lst->value);
		else if (lst->type == TOKEN_WORD)
			flag = 1;
		else if (lst->type == TOKEN_RED_IN || lst->type == TOKEN_RED_OUT
			|| lst->type == TOKEN_RED_APP || lst->type == TOKEN_HEREDOC)
			lst = lst->next;
		if (lst)
			lst = lst->next;
	}
	return (res);
}

static t_red	*ft_extract_redirections(t_token *lst)
{
	t_red	*res;
	int		type;

	res = NULL;
	while (lst)
	{
		if (lst->type == TOKEN_PIPE)
			break ;
		else if (lst->type == TOKEN_RED_IN || lst->type == TOKEN_RED_OUT
			|| lst->type == TOKEN_RED_APP)
		{
			type = lst->type - 1;
			lst = lst->next;
			ft_lstadd_back_red(&res, ft_lstnew_red(lst->value, type));
		}
		else if (lst->type == TOKEN_HEREDOC)
		{
			lst = lst->next;
			ft_lstadd_back_red(&res, ft_lstnew_red(ft_here_doc(lst->value), 1));
		}
		lst = lst->next;
	}
	return (res);
}

t_args	*ft_init_args(t_token *lst)
{
	t_args	*args;

	args = ft_calloc(sizeof(t_args));
	args->frist = ft_extract_command(lst);
	args->args = ft_extract_args(lst);
	args->is_sh = ft_is_sh(args->frist);
	args->is_cmd = ft_is_execute(args);
	args->valid = args->is_cmd || args->is_sh;
	args->_redirections = ft_extract_redirections(lst);
	return (args);
}
