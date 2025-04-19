/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjupille <sjupille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 16:45:59 by sjupille          #+#    #+#             */
/*   Updated: 2025/03/09 11:23:07 by sjupille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static void	exec_path(t_pipex *pipex, int command, int i)
{
	char	*temp;
	char	*cmd;

	temp = ft_strjoin2(pipex->paths[i], "/");
	cmd = ft_strjoin2(temp, pipex->cmds[command][0]);
	free(temp);
	if (access(cmd, F_OK | X_OK) == 0)
		execve(cmd, pipex->cmds[command], pipex->envp);
	free(cmd);
}

void	execute_cmd(t_pipex *pipex, int command)
{
	int	i;

	if (ft_strchr(pipex->cmds[command][0], '/'))
	{
		check_command_access(pipex->cmds[command][0]);
		execve(pipex->cmds[command][0], pipex->cmds[command], pipex->envp);
		free_pipex(pipex);
		exit(EXIT_FAILURE);
	}
	i = 0;
	while (pipex->paths[i])
	{
		exec_path(pipex, command, i);
		i++;
	}
	write(STDERR_FILENO, "Pipex: command not found: ", 26);
	write(STDERR_FILENO, pipex->cmds[command][0],
		ft_strlen(pipex->cmds[command][0]));
	write(STDERR_FILENO, "\n", 1);
}

void	first_cmd(t_pipex *pipex)
{
	int	infile_fd;

	if (pipex->here_doc)
		here_doc(pipex);
	infile_fd = open(pipex->infile, O_RDONLY);
	if (infile_fd < 0)
	{
		if (access(pipex->infile, F_OK) == -1)
			print_file_not_found(pipex->infile);
		else if (access(pipex->infile, R_OK) == -1)
			print_permission_denied(pipex->infile);
		close_pipes(pipex);
		free_pipex(pipex);
		exit(EXIT_FAILURE);
	}
	dup2(infile_fd, STDIN_FILENO);
	close(infile_fd);
	dup2(pipex->fd[1], STDOUT_FILENO);
	close_pipes(pipex);
	if (pipex->here_doc)
		unlink(pipex->infile);
	execute_cmd(pipex, 0);
}

void	median_cmd(t_pipex *pipex, int cmd_index)
{
	dup2(pipex->fd[2 * cmd_index - 2], STDIN_FILENO);
	dup2(pipex->fd[2 * cmd_index + 1], STDOUT_FILENO);
	close_pipes(pipex);
	execute_cmd(pipex, cmd_index);
}

void	last_cmd(t_pipex *pipex)
{
	int	outfile_fd;

	outfile_fd = open(pipex->outfile, O_WRONLY | O_CREAT | O_TRUNC
			* !(pipex->here_doc) | O_APPEND * (pipex->here_doc), 0644);
	if (outfile_fd < 0)
	{
		print_permission_denied(pipex->outfile);
		close_pipes(pipex);
		free_pipex(pipex);
		exit(EXIT_FAILURE);
	}
	dup2(outfile_fd, STDOUT_FILENO);
	close(outfile_fd);
	dup2(pipex->fd[2 * (pipex->pipes_index) - 2], STDIN_FILENO);
	close_pipes(pipex);
	execute_cmd(pipex, pipex->pipes_index);
}
