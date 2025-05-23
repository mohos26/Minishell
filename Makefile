SRCS =	sh/sh_cd.c \
		src/main.c \
		sh/sh_env.c \
		sh/sh_pwd.c \
		sh/sh_echo.c \
		sh/sh_exit.c \
		aid/ft_atoi.c \
		aid/ft_itoa.c \
		src/ft_exit.c \
		sh/sh_unset.c \
		src/ft_init.c \
		aid/ft_bzero.c \
		aid/ft_split.c \
		src/ft_do_sh.c \
		src/ft_is_sh.c \
		aid/ft_memcpy.c \
		aid/ft_strchr.c \
		aid/ft_strdup.c \
		aid/ft_strlen.c \
		aid/ft_isalnum.c \
		aid/ft_isalpha.c \
		aid/ft_isdigit.c \
		aid/ft_strjoin.c \
		aid/ft_strncmp.c \
		aid/ft_strnstr.c \
		src/env/ft_env.c \
		src/ft_execute.c \
		parsing/parsing.c \
		src/ft_here_doc.c \
		utils/ft_getcwd.c \
		aid/ft_putstr_fd.c \
		src/ft_check_dir.c \
		src/ft_init_args.c \
		aid/env/ft_lstnew.c \
		aid/ft_putendl_fd.c \
		parsing/ft_signal.c \
		src/env/ft_getenv.c \
		src/ft_is_execute.c \
		aid/env/ft_lstlast.c \
		aid/env/ft_lstsize.c \
		src/ft_init_prompt.c \
		src/ft_convert_env.c \
		utils/ft_is_number.c \
		aid/token/ft_lstnew.c \
		src/ft_extract_args.c \
		src/ft_handle_pipes.c \
		utils/ft_append_str.c \
		aid/env/ft_lstdel_in.c \
		aid/token/ft_lstlast.c \
		src/env/ft_build_env.c \
		src/ft_update_status.c \
		utils/ft_print_error.c \
		aid/env/ft_env_strdup.c \
		parsing/parsing_utils.c \
		src/ft_process_prompt.c \
		aid/env/ft_lstadd_back.c \
		sh/sh_export/sh_export.c \
		src/ft_extract_command.c \
		src/ft_process_command.c \
		src/ft_redirection_cmd.c \
		parsing/ft_handel_token.c \
		parsing/ft_syntax_error.c \
		parsing/ft_valid_quotes.c \
		utils/garbage_collector.c \
		aid/token/ft_lstadd_back.c \
		aid/redirection/ft_lstnew.c \
		aid/redirection/ft_lstlast.c \
		src/ft_extract_redirections.c \
		sh/sh_export/sh_export_utlis.c \
		sh/sh_export/sh_export_utlis2.c \
		aid/redirection/ft_lstadd_back.c \
		parsing/ft_parse_quoted_string.c \
		parsing/ft_analyze_next_segment.c

OBJS = ${SRCS:.c=.o}

NAME = minishell

%.o: %.c header.h
	cc -Wall -Wextra -Werror -c $< -o $@

all: ${NAME}

${NAME}: ${OBJS}
	cc $^ -lreadline -o $@
	# cc $^ -lreadline -fsanitize=address -g3 -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
