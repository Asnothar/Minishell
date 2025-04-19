/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjupille <sjupille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 15:12:27 by sjupille          #+#    #+#             */
/*   Updated: 2025/03/09 11:16:08 by sjupille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	here_doc(t_pipex *pipex)
{
	int		infile_fd;
	char	*line;

	infile_fd = open(pipex->infile, O_CREAT | O_TRUNC | O_WRONLY, 0644);
	if (infile_fd < 0)
	{
		perror("pipex");
		free_pipex(pipex);
		exit(EXIT_FAILURE);
	}
	line = get_next_line(0);
	while (line)
	{
		if (ft_strncmp(line, pipex->delimiter, ft_strlen(pipex->delimiter)) == 0
			&& line[ft_strlen(pipex->delimiter)] == '\n')
			break ;
		ft_putstr_fd(line, infile_fd);
		free(line);
		line = get_next_line(0);
	}
	free(line);
	close(infile_fd);
}

void	close_pipes(t_pipex *pipex)
{
	int	i;

	i = 0;
	while (i < 2 * pipex->pipes_index)
		close(pipex->fd[i++]);
}

int	main(int argc, char **argv, char **envp)
{
	int	i;

	i = 2;
	if (argc < 5 || (argc == 5 && ft_strncmp(argv[1], "here_doc", 8) == 0))
	{
		write(2, "Pipex: too few arguments\n", 24);
		return (EXIT_FAILURE);
	}
	while (i < argc - 1)
	{
		if (i == 2 && argc > 5 && ft_strncmp(argv[1], "here_doc", 8) == 0
			&& argv[i][0] == '\0')
			i++;
		if (argv[i][0] == '\0')
		{
			write(2, "Pipex: permission denied: empty command\n", 40);
			return (EXIT_FAILURE);
		}
		i++;
	}
	pipex(argc, argv, envp);
	return (EXIT_SUCCESS);
}
