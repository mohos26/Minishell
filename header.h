/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoussas <mhoussas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 10:18:37 by mhoussas          #+#    #+#             */
/*   Updated: 2025/05/31 15:20:10 by mhoussas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H

# define HEADER_H

# include <term.h>
# include <stdio.h>
# include <fcntl.h>
# include <errno.h>
# include <stdlib.h>
# include <limits.h>
# include <unistd.h>
# include <dirent.h>
# include <readline/history.h>
# include <readline/readline.h>

volatile sig_atomic_t	g_last_signal_received;

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
	enum e_token_type	type;
	struct s_token		*next;
	char				*value;
}						t_token;

typedef struct s_helper
{
	t_token	*lst;
	char	*aid;
	char	*var;
	int		flag;
	int		flag2;
}			t_helper;

typedef struct s_env
{
	struct s_env	*next;
	char			*name;
	char			*value;
	int				active;
}					t_env;

typedef struct s_redirections
{
	int						flag;
	int						flag2;
	struct s_redirections	*next;
	char					*file_name;
}							t_red;

typedef struct s_args
{
	int				is_sh;
	int				valid;
	char			*frist;
	char			**args;
	int				is_cmd;
	t_red			*_redirections;
}					t_args;

typedef struct s_prompt
{
	t_token	*lst;
	int		length;
	t_args	**args;
}			t_prompt;

/* --------------------------- aid files ------------------------------------ */
char		*ft_itoa(int n);
int			ft_isalnum(int c);
int			ft_isalpha(int c);
int			ft_isdigit(int c);
void		*ft_calloc(size_t size);
size_t		ft_strlen(const char *s);
int			ft_atoi(const char *str);
char		*ft_strdup(const char *s1);
void		ft_bzero(void *s, size_t n);
void		ft_putstr_fd(char *s, int fd);
void		ft_putendl_fd(char *s, int fd);
char		*ft_strchr(const char *s, int c);
char		**ft_split(const char *s, char c);
char		*ft_strjoin(char const *s1, char const *s2);
void		*ft_memcpy(void *dst, const void *src, size_t n);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*ft_strnstr(const char *haystack, const char *needle, size_t len);
/* env */
char		*ft_env_strdup(char *s);
int			ft_lstsize_env(t_env *lst);
void		ft_lstdel_in_env(t_env **lst, int i);
void		ft_lstadd_back_env(t_env **lst, t_env *new);
t_env		*ft_lstnew_env(char *name, char *value, int active);
/* redirection */
void		ft_lstadd_back_red(t_red **lst, t_red *new);
t_red		*ft_lstnew_red(char *name, int value, int flag2);
/* tokens */
t_token		*ft_lstlast_token(t_token *lst);
t_token		*ft_lstnew_token(char *value, int type);
void		ft_lstadd_back_token(t_token **lst, t_token *new);

/* ------------------------- shell commands --------------------------------- */
int			sh_pwd(void);
int			sh_env(void);
int			sh_cd(t_args *args);
int			sh_exit(t_args *args);
int			sh_echo(t_args *args);
int			sh_unset(t_args *args);
int			sh_export(t_args *args);

/* ------------------------- export ----------------------------------------- */
char		**ft_sort(void);
int			ft_append(char *var);
int			ft_valid_name(char *s);
int			ft_is_append(char *var);
char		**ft_var_split(char *s);
int			ft_is_onready(char *name);

/* -------------------------- src ------------------------------------------- */
void		ft_clean(void);
int			ft_is_sh(char *s);
void		ft_init(char **env);
void		ft_exit(int status);
t_env		**ft_env(t_env *lst);
int			ft_is_number(char *s);
int			ft_check_dir(char *s);
char		*ft_readline(char *s);
char		**ft_convert_env(void);
int			ft_do_sh(t_args *args);
char		*ft_getenv(char *name);
t_prompt	*ft_init_prompt(char *s);
int			ft_execute(t_args *args);
t_env		*ft_build_env(char **env);
t_args		*ft_init_args(t_token *lst);
int			ft_is_execute(t_args *args);
char		*ft_here_doc(char *limiter);
void		ft_update_status(int status);
char		*ft_getcwd(char *s, size_t n);
int			ft_do_redirection(t_red *lst);
char		**ft_extract_args(t_token *lst);
char		*ft_append_str(char	*s, char c);
int			ft_process_command(t_args *args);
char		*ft_extract_command(t_token *lst);
int			ft_handle_pipes(t_prompt *prompt);
void		ft_process_prompt(t_prompt *prompt);
t_red		*ft_extract_redirections(t_token *lst, int *flag);
void		ft_print_error(char *command_name, char *arg, char *arg2);

/* ---------------------------- parsing ------------------------------------- */
int			ft_is_space(char c);
void		ft_signal_util(void);
int			ft_valid_quotes(char *s);
void		ft_heredoc_signal(int sig);
void		ft_signal_handler(int sig);
t_token		*ft_split_args(char *prompt);
int			ft_is_valid(char *s, char c);
char		*ft_expand_quotes(char *var);
void		ft_update_ctrl_flag(int flag);
int			ft_syntax_error(t_token *tokens);
void		ft_handle_token(t_helper *helper, int type);
char		*ft_parse_quoted_string(char *prompt, char **aid);
char		*ft_analyze_next_segment(char *prompt, t_helper *helper);
char		*ft_expand_split(t_token **lst, char *aid, char *var, int flag);
char		**ft_split_wspace(const char *s);

#endif
