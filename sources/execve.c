/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaufil <abeaufil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 10:16:24 by abeaufil          #+#    #+#             */
/*   Updated: 2025/04/07 18:43:40 by abeaufil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/pipex.h"

int	search_path(char **env)
{
	char	*str;
	int		i;

	str = "PATH=";
	i = 0;
	while (env[i] != NULL)
	{
		if (ft_strncmp(str, env[i], 5) == 0)
			return (i);
		i++;
	}
	return (-1);
}

char	*join_path(char *dir, char *cmd)
{
	char	*temp;
	char	*full_cmd;

	temp = ft_strjoin("/", cmd);
	if (!temp)
		return (NULL);
	full_cmd = ft_strjoin(dir, temp);
	free(temp);
	return (full_cmd);
}

int	check_exec(char *argv, char **cmd, char **env, char *path_cmd)
{
	if (access(argv, F_OK | X_OK) == 0)
		execve(argv, cmd, env);
	else if (access(path_cmd, F_OK | X_OK) == 0)
		execve(path_cmd, cmd, env);
	return (0);
}

void	execute_absolute_path(char **cmd, char **path, char **env)
{
	if (cmd[0][0] == '/' || (cmd[0][0] == '.' && cmd[0][1] == '/'))
	{
		if (access(cmd[0], F_OK) == 0)
		{
			if (access(cmd[0], X_OK) == 0)
			{
				execve(cmd[0], cmd, env);
				perror("execve failed");
			}
			else
				perror("Permission denied");
		}
		else
			perror("Command not found");
	}
	exit_free(path, cmd, 0, 1);
}

void	exec_path(char *argv, char **env)
{
	char	**path;
	char	**cmd;
	char	*path_cmd;
	int		i;

	path = ft_split(env[search_path(env)], ':');
	cmd = ft_split(argv, ' ');
	if (!cmd[0] || !cmd[0][0] || !cmd)
		exit_free(path, cmd, 1, 1);
	if (cmd[0][0] == '/' || (cmd[0][0] == '.' && cmd[0][1] == '/'))
		execute_absolute_path(cmd, path, env);
	i = 0;
	while (path[i++])
	{
		path_cmd = join_path(path[i], cmd[0]);
		if (!path_cmd)
			break ;
		if (check_exec(argv, cmd, env, path_cmd))
			exit(0);
		free(path_cmd);
	}
	exit_free(path, cmd, 1, 1);
}
