


#include "../../header/minishell.h"

void	here_doc1(int write_end, char *limiter)
{
	char	*str;
	char	*tmp;

	while (1)
	{
		str = readline(" > ");
		if (!str || ft_strcmp(str, limiter) == 0)
		{
			free(str);
			break ;
		}
		tmp = ft_strjoin(str, "\n");
		free(str);
		if (!tmp)
			break ;
		write(write_end, tmp, ft_strlen(tmp));
		free(tmp);
	}
}

int	here_doc(t_shell *shell)
{
	int	fd[2];

	if (pipe(fd) == -1)
		return (perror("minishell: pipe"), -1);
	here_doc1(fd[1], shell->heredoc_delim);
	close(fd[1]);
	if (dup2(fd[0], STDIN_FILENO) == -1)
	{
		perror("minishell: dup2");
		close(fd[0]);
		return (-1);
	}
	close(fd[0]);
	return (1);
}
