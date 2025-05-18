/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoussas <mhoussas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 10:18:37 by mhoussas          #+#    #+#             */
/*   Updated: 2025/05/18 19:31:17 by mhoussas         ###   ########.fr       */
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

enum	e_token_type
{
	TOKEN_WORD,
	TOKEN_PIPE,
	TOKEN_RED_IN,
	TOKEN_RED_OUT,
	TOKEN_RED_APP,
	TOKEN_HEREDOC,
};

typedef struct s_token
{
	char				*value;
	struct s_token		*next;
	enum e_token_type	type;
}						t_token;

typedef struct s_redirections
{
	char					*file_name;
	int						flag;
	struct s_redirections	*next;
}							t_red;

typedef struct s_args
{
	char			*frist;
	char			**args;
	int				is_cmd;
	int				is_sh;
	int				valid;
	t_red			*_redirections;
}					t_args;

typedef struct s_prompt
{
	t_args	**args;
	t_token	*lst;
	int		length;
}			t_prompt;

typedef struct s_env
{
	char			*name;
	char			*value;
	int				active;
	struct s_env	*next;
}					t_env;

/* --------------------------- aid files ------------------------------- */
void		*ft_memcpy(void *dst, const void *src, size_t n);
char		**ft_split(const char *s, char c);
char		*ft_strdup(const char *s1);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
size_t		ft_strlen(const char *s);
char		*ft_strjoin(char const *s1, char const *s2);
void		ft_putstr_fd(char *s, int fd);
int			ft_isalnum(int c);
int			ft_isalpha(int c);
char		*ft_strchr(const char *s, int c);
void		ft_bzero(void *s, size_t n);
int			ft_atoi(const char *str);
int			ft_isdigit(int c);
char		*ft_itoa(int n);
int			ft_lstsize(t_env *lst);
t_env		*ft_lstnew(char *name, char *value, int active);
char		*ft_strnstr(const char *haystack, const char *needle, size_t len);
void		ft_putendl_fd(char *s, int fd);
/* env */
t_env		*ft_lstnew_env(char *name, char *value, int active);
void		ft_lstadd_back_env(t_env **lst, t_env *new);
void		ft_lstdel_in_env(t_env **lst, int i);
int			ft_lstsize_env(t_env *lst);
t_env		*ft_lstlast_env(t_env *lst);
char		*ft_env_strdup(char *s);
/* redirection */
void		ft_lstadd_back_red(t_red **lst, t_red *new);
void		ft_lstdel_in_red(t_red **lst, int i);
t_red		*ft_lstnew_red(char *name, int value);
t_red		*ft_lstlast_red(t_red *lst);
int			ft_lstsize_red(t_red *lst);
char		*ft_itoa(int n);
char		*ft_here_doc(char *limiter);

/* ------------------------- shell commands --------------------------------- */
void		sh_pwd(void);
void		sh_exit(t_args *args);
void		sh_echo(t_args *args);
void		sh_cd(t_args *args);
void		sh_export(t_args *args);
void		sh_unset(t_args *args);
void		sh_env(void);

/* -------------------------- utils ---------------------------------------- */
int			ft_is_execute(t_args *args);
int			ft_is_sh(char *s);
int			ft_do_sh(t_args *args);
void		ft_print_error(char *command_name, char *arg, char *arg2);
void		*ft_calloc(size_t size);
void		ft_exit(int status);
t_args		*ft_init_args(t_token *lst);
void		ft_init(char **env);
int			ft_check_redirections(char **lst);
char		*ft_get_file(char **lst);
int			ft_do_redirection(t_red *lst);
void		ft_close_redirection(t_red *lst);
t_prompt	*ft_init_prompt(char *s);
t_env		*ft_build_env(char **env);
t_env		**ft_env(t_env *lst);
char		*ft_env_strdup(char *s);
char		**ft_convert_env(void);
void		ft_clean(void);
void		ft_pipe_redirection(int fd, int flag);
void		ft_close_pipe_redirection(int flag);
int			ft_process_prompt(t_prompt *prompt);
char		*ft_getenv(char *name);
int			ft_is_number(char *s);
int			ft_check_dir(char *s);
int			ft_process_command(t_args *args);
int			ft_execute(t_args *args);
char		*ft_append_str(char	*s, char c);

/* ------------------------- export -------------------------------------- */
char		**ft_var_split(char *s);
int			ft_valid_name(char *s);
int			ft_is_onready(char *name);
int			ft_is_append(char *var);
void		ft_append(char *var);

/* ---------------------------- parsing ------------------------------------*/
int			ft_valid_quotes(char *s);
t_token		*ft_split_args(char *prompt);
t_token		*ft_lstlast_token(t_token *lst);
int			ft_syntax_error(t_token *tokens);
t_token		*ft_lstnew_token(char *value, int type);
void		ft_lstadd_back_token(t_token **lst, t_token *new);
void		signal_util(void);

#endif
