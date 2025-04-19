/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjupille <sjupille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 14:41:27 by sjupille          #+#    #+#             */
/*   Updated: 2025/02/24 13:37:47 by sjupille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <fcntl.h>
# include "get_next_line.h"

typedef struct s_pipex
{
	char	*infile;
	char	*outfile;
	int		*fd;
	char	**paths;
	char	***cmds;
	int		cmds_index;
	int		pipes_index;
	int		here_doc;
	char	*delimiter;
	char	**envp;
}				t_pipex;

/*------------------------- libft utils -----------------------------------*/

void	ft_putstr_fd(char *s, int fd);
int		ft_strncmp(char *s1, char *s2, size_t n);
char	**ft_split(const char *s, char c);
void	check_command_access(char *cmd);

/*------------------------- init pipex ------------------------------------*/

int		init_pipes(t_pipex *pipex, int argc, char **argv, char **envp);
int		init_path(t_pipex *pipex, char **argv, char **envp);
void	init_pipex(t_pipex *pipex, int argc, char **argv, char **envp);
void	free_pipex(t_pipex *pipex);
void	free_cmds(t_pipex *pipex);
void	free_paths(t_pipex *pipex);
void	print_file_not_found(char *filename);
void	print_permission_denied(char *filename);
void	close_pipes(t_pipex *pipex);

/*---------------------------- pipex --------------------------------------*/

void	execute_cmd(t_pipex *pipex, int command);
void	first_cmd(t_pipex *pipex);
void	median_cmd(t_pipex *pipex, int cmd_index);
void	last_cmd(t_pipex *pipex);
void	handle_pipes(t_pipex *pipex);
void	wait_free(t_pipex *pipex);
void	here_doc(t_pipex *pipex);
void	pipex(int argc, char **argv, char **envp);
int		main(int argc, char **argv, char **envp);

#endif
