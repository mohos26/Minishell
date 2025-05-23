/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_prompt.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoussas <mhoussas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 10:32:34 by mhoussas          #+#    #+#             */
/*   Updated: 2025/05/21 17:56:30 by mhoussas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

static int	ft_len(t_token *lst)
{
	int	len;

	len = 1;
	while (lst)
	{
		if (lst->type == TOKEN_PIPE)
			len++;
		lst = lst->next;
	}
	return (len);
}

static t_args	**ft_get_args(t_token *lst, int len)
{
	t_args	**args;
	int		i;

	args = ft_calloc(sizeof(t_args *) * (len + 1));
	i = 0;
	while (i < len)
	{
		args[i++] = ft_init_args(lst);
		if (!args[i - 1])
			return (NULL);
		while (lst && lst->type != TOKEN_PIPE)
			lst = lst->next;
		if (lst)
			lst = lst->next;
	}
	args[i] = NULL;
	return (args);
}

static int	ft_check_maximum_her_doc(t_token *lst)
{
	int	len;

	len = 0;
	while (lst)
	{
		if (lst->type == TOKEN_HEREDOC)
			len++;
		if (len >= 17)
		{
			ft_putendl_fd("Minishell: maximum here-document count exceeded", 2);
			return (1);
		}
		lst = lst->next;
	}
	return (0);
}

t_prompt	*ft_init_prompt(char *s)
{
	t_prompt	*prompt;
	t_token		*lst;

	if (!ft_valid_quotes(s))
		return (ft_print_error("syntax error", "unexpected end of file",
				"Nothing"), NULL);
	lst = ft_split_args(s);
	if (ft_syntax_error(lst))
		return (NULL);
	if (ft_check_maximum_her_doc(lst))
		ft_exit(2);
	prompt = ft_calloc(sizeof(t_prompt));
	prompt->length = ft_len(lst);
	prompt->args = ft_get_args(lst, prompt->length);
	if (!prompt->args)
		return (ft_update_status(1), NULL);
	return (prompt);
}
