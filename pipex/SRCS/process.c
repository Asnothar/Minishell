/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjupille <sjupille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 16:41:48 by sjupille          #+#    #+#             */
/*   Updated: 2025/03/09 11:15:59 by sjupille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	wait_free(t_pipex *pipex)
{
	close_pipes(pipex);
	while (1)
		if (wait(NULL) == -1)
			break ;
	free_pipex(pipex);
}

void	handle_pipes(t_pipex *pipex)
{
	int		i;
	pid_t	pid;

	i = -1;
	while (++i < pipex->cmds_index)
	{
		pid = fork();
		if (pid < 0)
		{
			perror("pipex");
			free_pipex(pipex);
			exit(EXIT_FAILURE);
		}
		else if (pid == 0)
		{
			if (i == 0)
				first_cmd(pipex);
			else if (i < pipex->pipes_index)
				median_cmd(pipex, i);
			else
				last_cmd(pipex);
		}
		if (i == 0 && pipex->here_doc)
			wait(NULL);
	}
}

void	pipex(int argc, char **argv, char **envp)
{
	t_pipex	pipex;

	init_pipex(&pipex, argc, argv, envp);
	handle_pipes(&pipex);
	wait_free(&pipex);
}
