SRCS = src/main.c aid/ft_atoi.c aid/ft_isdigit.c aid/ft_putstr_fd.c aid/ft_strjoin.c \
aid/ft_bzero.c aid/ft_itoa.c aid/ft_split.c aid/ft_strlen.c aid/ft_isalnum.c \
aid/ft_memcpy.c aid/ft_strchr.c aid/ft_strncmp.c aid/ft_isalpha.c \
aid/ft_putendl_fd.c aid/ft_strdup.c aid/ft_strnstr.c aid/env/ft_lstsize.c \
aid/env/ft_lstnew.c aid/env/ft_lstlast.c aid/env/ft_lstdel_in.c \
aid/env/ft_lstadd_back.c aid/redirection/ft_lstsize.c \
aid/redirection/ft_lstnew.c aid/redirection/ft_lstlast.c \
aid/redirection/ft_lstdel_in.c aid/redirection/ft_lstadd_back.c \
sh/sh_cd.c sh/sh_echo.c sh/sh_env.c sh/sh_exit.c sh/sh_pwd.c \
sh/sh_unset.c sh/sh_export/sh_export.c sh/sh_export/sh_export_utlis.c \
sh/sh_export/sh_export_utlis2.c src/ft_do_sh.c src/ft_execute.c src/ft_init.c \
src/ft_init_args.c src/ft_init_prompt.c src/ft_is_execute.c \
src/ft_process_command.c src/ft_process_prompt.c src/ft_redirection_cmd.c \
src/ft_redirection_pipe.c src/ft_redirections_parsing.c src/main.c \
src/parsing.c src/env/ft_build_env.c src/env/ft_getenv.c src/env/ft_env.c \
utils/ft_print_error.c utils/garbage_collector.c utils/ft_is_number.c \
src/env/ft_env_strdup.c src/ft_check_dir.c parsing/main.c aid/token/ft_lstadd_back.c \
aid/token/ft_lstlast.c aid/token/ft_lstnew.c src/ft_here_doc.c aid/ft_itoa.c \
parsing/ft_signal.c utils/ft_append_str.c

NAME = minishell

OBJS = ${SRCS:.c=.o}

%.o: %.c header.h
	cc -Wall -Wextra -Werror  -c $< -o $@

all: ${NAME}

${NAME}: ${OBJS}
	cc $^ -lreadline -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
