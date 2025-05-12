


#include "../../header/minishell.h"

int	pipe_count(t_shell *minishell)
{
	t_token	*token;
	int		count;

	token = minishell->tokens;
	count = 0;
	while (token)
	{
		if (token->value == PIPE)
			count++;
		token = token->next;
	}
	return (count);
}

void	pipex(t_shell *minishell, int **fd, int pipe_index, int pipe_count)
{
	if (pipe_index != 0 && minishell->infile == NULL)
	{
		if (dup2(fd[pipe_index - 1][0], STDIN_FILENO) == -1)
		{
			close_fd(fd, pipe_count);
			perror("minishell: pipe read dup2");
			exit(EXIT_FAILURE);
		}
	}
	if (pipe_index < pipe_count)
	{
		if (dup2(fd[pipe_index][1], STDOUT_FILENO) == -1)
		{
			close_fd(fd, pipe_count);
			perror("minishell: pipe write dup2");
			exit(EXIT_FAILURE);
		}
	}
	close_fd(fd, pipe_count);
}
void	close_fd(int **fd, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		close(fd[i][0]);
		close(fd[i][1]);
		i++;
	}
}
void	waiting_childs(t_shell *minishell, int nb_cmds)
{
	int	i;
	int	status;

	if (nb_cmds == 1 && minishell->isbuiltin)
		return ;
	i = 0;
	while (i++ < nb_cmds)
	{
		wait(&status);
		if (WIFSIGNALED(status))
			minishell->last_exit_status = 128 + WTERMSIG(status);
		else if (WIFEXITED(status))
			minishell->last_exit_status = WEXITSTATUS(status);
	}
}
