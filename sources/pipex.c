/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaufil <abeaufil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 09:19:50 by abeaufil          #+#    #+#             */
/*   Updated: 2025/04/07 17:35:28 by abeaufil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/pipex.h"

void	check_infile(char *file)
{
	if (access(file, F_OK) == -1)
	{
		ft_printf("no such file or directory: %s\n", file);
		exit(1);
	}
	if (access(file, R_OK) == -1)
	{
		ft_printf("permissions denied: %s\n", file);
		exit(1);
	}
}

void	check_outfile(char *file)
{
	int	fd;

	fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
	{
		ft_printf("permissions denied: %s\n", file);
		exit(1);
	}
	close(fd);
}

void	child_1(char *file, char *cmd, int pipefd[2], char **env)
{
	int	fd;

	if (access(file, F_OK) == -1)
		return (ft_printf("no such file or directory : %s\n", file), \
				close(pipefd[0]), close(pipefd[1]), exit(1));
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (ft_printf("permissions denied : %s\n", file), \
				close(pipefd[0]), close(pipefd[1]), exit(1));
	if (dup2(fd, STDIN_FILENO) == -1
		|| dup2(pipefd[1], STDOUT_FILENO) == -1)
		return (ft_printf("failed to duplicate file descriptors\n"), \
				close(fd), close(pipefd[0]), close(pipefd[1]), exit(1));
	if (cmd[0] == '\0')
		return (ft_printf("Empty command\n"), \
				close(fd), close(pipefd[0]), close(pipefd[1]), exit(1));
	close(pipefd[0]);
	close(pipefd[1]);
	close(fd);
	exec_path(cmd, env);
}

void	child_2(char *file, char *cmd, int pipefd[2], char **env)
{
	int	fd;

	fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
		return (ft_printf("permissions denied : %s\n", file),
			close(pipefd[0]), close(pipefd[1]), exit(1));
	if (dup2(pipefd[0], STDIN_FILENO) == -1
		|| dup2(fd, STDOUT_FILENO) == -1)
		return (ft_printf("failed to duplicate file descriptors\n"), \
				close(fd), close(pipefd[0]), close(pipefd[1]), exit(1));
	if (cmd[0] == '\0')
		return (ft_printf("Empty command\n"), \
				close(fd), close(pipefd[0]), close(pipefd[1]), exit(1));
	close(pipefd[0]);
	close(pipefd[1]);
	close(fd);
	exec_path(cmd, env);
}

int	main(int argc, char **argv, char **env)
{
	int		pipefd[2];
	pid_t	pid1;
	pid_t	pid2;

	if (argc != 5)
		return (ft_printf("wrong arguments count\n"), 1);
	check_infile(argv[1]);
	check_outfile(argv[4]);
	if (pipe(pipefd) == -1)
		return (ft_printf("Error: pipe\n"), 1);
	pid1 = fork();
	if (pid1 == -1)
		return (ft_printf("Error: fork 1\n"), 1);
	else if (pid1 == 0)
		child_1(argv[1], argv[2], pipefd, env);
	pid2 = fork();
	if (pid2 == -1)
		return (ft_printf("Error: fork 2\n"), 1);
	else if (pid2 == 0)
		child_2(argv[4], argv[3], pipefd, env);
	close(pipefd[0]);
	close(pipefd[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
	return (0);
}
