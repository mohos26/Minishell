/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoussas <mhoussas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 10:18:37 by mhoussas          #+#    #+#             */
/*   Updated: 2025/02/23 11:29:45 by mhoussas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H

# define HEADER_H

# include <libc.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/ioctl.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <dirent.h>
# include <term.h>
# include <curses.h>

/* aid files */
void	*ft_memcpy(void *dst, const void *src, size_t n);
char	**ft_split(const char *s, char c);
char	*ft_strdup(const char *s1);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
void	ft_putstr_fd(char *s, int fd);
int		ft_isalnum(int c);
int		ft_isalpha(int c);
char	*ft_strchr(const char *s, int c);
void	ft_bzero(void *s, size_t n);

/* shell commands */
int		sh_pwd(void);
void	sh_exit(void);
void	sh_echo(char **lst);
void	sh_cd(char *s);
void	sh_export(char **args, char ***env);
void	sh_unset(char **args, char ***enp);
void	sh_env(char **env);

/* utils */
int		ft_is_valid(char *s);
int		ft_is_execute(char *s);
int		ft_is_shell_command(char *s);
void	ft_do_shell_command(char **lst, char ***env);
void	ft_print_error(char *command_name, char *arg, char *arg2);
void	*ft_calloc(size_t size);
void	ft_exit(int status);

/* export */
char	**ft_add_var(char **env, char *var);
char	**ft_export_split(char *s);
int		ft_valid_name(char *s);
int		ft_is_onready(char **env, char *name);

#endif
