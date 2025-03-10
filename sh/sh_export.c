/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoussas <mhoussas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 18:42:43 by mhoussas          #+#    #+#             */
/*   Updated: 2025/03/10 09:38:20 by mhoussas         ###   ########.fr       */
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
			printf("declare -x %s\n", *env);
		env++;
	}
}

static void	ft_reset_var(char *s)
{
	char	**var;
	t_list	*env;

	env = *ft_getenv(NULL);
	var = ft_export_split(s);
	while (**(var + 1) && env)
	{
		if ((!ft_strncmp(env->name, *var, ft_strlen(*var) + 1))
			&& ft_strncmp(*var, "_", 2))
		{
			free(env->value);
			env->value = ft_local_strdup(var[1]);
			env->active = 1;
			break ;
		}
		env = env->next;
	}
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
		var = ft_export_split(*lst);
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
