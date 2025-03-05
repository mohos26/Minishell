/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoussas <mhoussas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 10:18:37 by mhoussas          #+#    #+#             */
/*   Updated: 2025/03/04 15:36:58 by mhoussas         ###   ########.fr       */
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

typedef struct s_args
{
	char	*frist;
	char	**args;
	int		is_cmd;
	int		is_sh;
	int		valid;
	int		redirections;
	char	*file_redirections;
	char	***env;
}			t_args;

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
int		ft_atoi(const char *str);
int		ft_isdigit(int c);
char	*ft_itoa(int n);

/* shell commands */
void	sh_pwd(void);
void	sh_exit(void);
void	sh_echo(t_args *args);
void	sh_cd(t_args *args);
void	sh_export(t_args *args);
void	sh_unset(t_args *args);
void	sh_env(t_args *args);
int		ft_is_forbiden(char *name);

/* utils */
int		ft_is_execute(t_args *args);
int		ft_is_sh(char *s);
void	ft_do_sh(t_args *args);
void	ft_print_error(char *command_name, char *arg, char *arg2);
void	*ft_calloc(size_t size);
void	ft_exit(int status);
t_args	*ft_init_args(char *s, char ***env);
void	ft_execute(t_args *args);
pid_t	ft_fork(void);
void	ft_init(char ***enp);
int		ft_check_redirections(char **lst);
char	*ft_get_file(char **lst);
void	ft_do_redirection(t_args *args);
void	ft_close_redirection(t_args *args);

/* export */
char	**ft_add_var(char **env, char *var);
char	**ft_export_split(char *s);
int		ft_valid_name(char *s);
int		ft_is_onready(char **env, char *name);

#endif
