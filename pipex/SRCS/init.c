/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjupille <sjupille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 16:37:25 by sjupille          #+#    #+#             */
/*   Updated: 2025/03/09 11:16:25 by sjupille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static char	**get_path(char **envp)
{
	int	i;

	i = 0;
	while (ft_strncmp(envp[i], "PATH=", 5))
		++i;
	return (ft_split(envp[i] + 5, ':'));
}

int	init_pipes(t_pipex *pipex, int argc, char **argv, char **envp)
{
	int	i;

	pipex->infile = argv[1];
	pipex->outfile = argv[argc - 1];
	if (!ft_strncmp(pipex->infile, "here_doc", ft_strlen(pipex->infile)))
	{
		pipex->here_doc = 1;
		pipex->delimiter = argv[2];
	}
	pipex->envp = envp;
	pipex->cmds_index = argc - 3 - pipex->here_doc;
	pipex->pipes_index = argc - 4 - pipex->here_doc;
	pipex->fd = (int *) malloc(sizeof(int) * 2 * (pipex->pipes_index));
	if (pipex->fd == NULL)
		return (1);
	i = 0;
	while (i < 2 * (pipex->pipes_index))
	{
		if (pipe(pipex->fd + i) < 0)
			return (1);
		i += 2;
	}
	return (0);
}

int	init_path(t_pipex *pipex, char **argv, char **envp)
{
	int	i;

	pipex->paths = get_path(envp);
	if (pipex->paths == NULL)
	{
		free_paths(pipex);
		return (1);
	}
	pipex->cmds = (char ***) malloc(sizeof(char **) * (pipex->cmds_index));
	if (pipex->cmds == NULL)
	{
		free_cmds(pipex);
		return (1);
	}
	i = -1;
	while (++i < pipex->cmds_index)
	{
		pipex->cmds[i] = ft_split(argv[i + 2 + pipex->here_doc], ' ');
		if (pipex->cmds[i] == NULL)
		{
			free_cmds(pipex);
			return (1);
		}
	}
	return (0);
}

void	init_pipex(t_pipex *pipex, int argc, char **argv, char **envp)
{
	pipex->fd = NULL;
	pipex->paths = NULL;
	pipex->cmds = NULL;
	pipex->here_doc = 0;
	pipex->delimiter = NULL;
	if (init_pipes(pipex, argc, argv, envp))
	{
		perror("init pipex failed:");
		free_pipex(pipex);
		exit(EXIT_FAILURE);
	}
	if (init_path(pipex, argv, envp))
	{
		perror("pipex path failed:");
		free_pipex(pipex);
		exit(EXIT_FAILURE);
	}
}
