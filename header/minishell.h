/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaufil <abeaufil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 17:42:19 by abeaufil          #+#    #+#             */
/*   Updated: 2025/04/29 16:17:05 by abeaufil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../sources/ultimate_libft/header/ultimate_libft.h"

# include <readline/readline.h>
# include <readline/history.h>
# include <sys/wait.h>
# include <signal.h>
# include <sys/stat.h>
# include <dirent.h>
# include <string.h>
# include <termios.h>
# include <sys/ioctl.h>
# include <termcap.h>

//	parsing
//		parsing1.c
int		check_quotes(char *line);
int		check_pipe(char *line);
int		check_redirection(char *line);
int		check_special_characters(char *line);
int		check_syntax(char *line);

//	utils
//		utils1.c
int		skip_whitespaces(const char *str, int i, int len);
void	print_tokens(char **tokens);
//		tokens.c
char	*handle_quotes(const char *line, size_t *i, size_t len);
char	*handle_special_characters(const char *line, size_t *i);
char	**initialize_tokens(size_t len);
char	*process_token(const char *line, size_t *i, size_t len);
char	**tokenize_input(const char *line);

#endif
