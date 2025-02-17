/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoussas <mhoussas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 10:18:37 by mhoussas          #+#    #+#             */
/*   Updated: 2025/02/17 15:25:44 by mhoussas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H

# define HEADER_H

# include <libc.h>
# include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <sys/ioctl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>

#include <term.h>
#include <curses.h>

void	*ft_memcpy(void *dst, const void *src, size_t n);
char	**ft_split(const char *s, char c);
char	*ft_strdup(const char *s1);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_is_valid(char *s);
size_t	ft_strlen(const char *s);
int		ft_is_execute(char *s);
int		ft_pwd(void);
int		ft_is_shell_command(char *s);
void	ft_do_shell_command(char *s);

#endif