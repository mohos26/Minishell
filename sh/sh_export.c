/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoussas <mhoussas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 18:42:43 by mhoussas          #+#    #+#             */
/*   Updated: 2025/04/13 22:37:38 by mhoussas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

static char	**ft_sort(void)
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

static void	ft_print_env(void)
{
	char	**env;

	env = ft_sort();
	while (env && *env)
	{
		if (ft_strncmp(*env, "_=", 2))
			ft_putendl_fd(ft_strjoin("declare -x ", *env), 1);
		env++;
	}
}

static void	ft_add_var(char *var)
{
	char	**res;

	res = ft_var_split(var);
	ft_lstadd_back(ft_env(NULL), ft_lstnew(ft_env_strdup(res[0]),
			ft_env_strdup(res[1]), !!ft_strchr(var, '=')));
}

static void	ft_reset_var(char *s)
{
	char	**var;
	t_list	*env;

	env = *ft_env(NULL);
	var = ft_var_split(s);
	while (**(var + 1) && env)
	{
		if ((!ft_strncmp(env->name, *var, ft_strlen(*var) + 1))
			&& ft_strncmp(*var, "_", 2))
		{
			free(env->value);
			env->value = ft_env_strdup(var[1]);
			env->active = 1;
			break ;
		}
		env = env->next;
	}
}

static void	ft_aid(char **var)
{
	t_list	*env;
	char	*tmp;

	env = *ft_env(NULL);
	while (**(var + 1) && env)
	{
		if ((!ft_strncmp(env->name, *var, ft_strlen(*var) + 1))
			&& ft_strncmp(*var, "_", 2))
		{
			tmp = env->value;
			env->value = ft_env_strdup(ft_strjoin(tmp, var[1]));
			env->active = 1;
			free(tmp);
			break ;
		}
		env = env->next;
	}
}

static void	ft_aid2(char **var) // He Need To Create A local split For Append, He Need More Time
{
	ft_lstadd_back(ft_env(NULL), ft_lstnew(ft_env_strdup(var[0]),
			ft_env_strdup(var[1]), 1));
}

static int	ft_is_append(char *var)
{
	return (ft_strnstr(var, "+=", INT_MAX) != NULL);
}

static void	ft_append(char *var)
{
	char	**lst;

	lst = ft_split(var, '+');
	(*(lst + 1))++;
	if (ft_valid_name(*lst))
	{
		if (ft_is_onready(*lst))
			ft_aid(lst);
		else
			ft_aid2(lst);
	}
	else
		ft_print_error("export", var, "not a valid identifier");
}

void	sh_export(t_args *args)
{
	char	**var;
	char	**lst;

	lst = args->args;
	if (!lst || !*lst)
		ft_print_env();
	while (lst && *lst)
	{
		if (ft_is_append(*lst))
			return (ft_append(*lst));
		var = ft_var_split(*lst);
		if (ft_valid_name(*var))
		{
			if (ft_is_onready(*var))
				ft_reset_var(*lst);
			else
				ft_add_var(*lst);
		}
		else
			ft_print_error("export", *lst, "not a valid identifier");
		lst++;
	}
}
