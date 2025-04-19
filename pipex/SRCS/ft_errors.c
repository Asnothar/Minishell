/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjupille <sjupille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 16:27:04 by sjupille          #+#    #+#             */
/*   Updated: 2025/03/09 11:19:48 by sjupille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	free_cmds(t_pipex *pipex)
{
	int	i;
	int	j;

	if (pipex->cmds != NULL)
	{
		i = 0;
		while (i < pipex->cmds_index)
		{
			if (pipex->cmds[i] != NULL)
			{
				j = 0;
				while (pipex->cmds[i][j] != NULL)
				{
					free(pipex->cmds[i][j]);
					pipex->cmds[i][j++] = NULL;
				}
				free(pipex->cmds[i]);
				pipex->cmds[i] = NULL;
			}
			++i;
		}
		free(pipex->cmds);
		pipex->cmds = NULL;
	}
}

void	free_paths(t_pipex *pipex)
{
	int	i;

	if (pipex->paths != NULL)
	{
		i = 0;
		while (pipex->paths[i] != NULL)
		{
			free(pipex->paths[i]);
			pipex->paths[i++] = NULL;
		}
		free(pipex->paths);
		pipex->paths = NULL;
	}
}

void	free_pipex(t_pipex *pipex)
{
	free(pipex->fd);
	free_cmds(pipex);
	free_paths(pipex);
}

void	print_file_not_found(char *filename)
{
	write(STDERR_FILENO, "Pipex: no such file or directory: ", 34);
	write(STDERR_FILENO, filename, ft_strlen(filename));
	write(STDERR_FILENO, "\n", 1);
}

void	print_permission_denied(char *filename)
{
	write(STDERR_FILENO, "Pipex: permission denied: ", 26);
	write(STDERR_FILENO, filename, ft_strlen(filename));
	write(STDERR_FILENO, "\n", 1);
}
