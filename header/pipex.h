/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaufil <abeaufil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 17:42:19 by abeaufil          #+#    #+#             */
/*   Updated: 2025/04/01 13:35:16 by abeaufil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../sources/ultimate_libft/header/ultimate_libft.h"

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <fcntl.h>

// execve.c
int		search_path(char **env);
char	*join_path(char *dir, char *cmd);
int		check_exec(char *argv, char **cmd, char **env, char *path_cmd);
void	exec_path(char *argv, char **env);

// pipex.c
void	child_1(char *file, char *cmd, int pipefd[2], char **env);
void	child_2(char *file, char *cmd, int pipefd[2], char **env);
int		main(int argc, char **argv, char **env);

// utils.c
void	free_tab(char **str);
void	free_all(char **str1, char **str2);
void	exit_free(char **path, char **cmd, int status, int stat);

#endif
