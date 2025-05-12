


// #include "../../header/minishell.h"

// int	open_infile(char *file)
// {
// 	int	fd = open(file, O_RDONLY);
// 	if (fd < 0)
// 		perror(file);
// 	return (fd);
// }

// int	open_outfile(char *file, t_token_type type)
// {
// 	int	fd;

// 	if (type == REDIR_OUT)
// 		fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
// 	else if (type == APPEND)
// 		fd = open(file, O_WRONLY | O_CREAT | O_APPEND, 0644);
// 	else
// 		return (-1);
// 	if (fd < 0)
// 		perror(file);
// 	return (fd);
// }

// void	in_redir(t_shell *shell)
// {
// 	int	fd;

// 	if (shell->infile)
// 	{
// 		fd = open_infile(shell->infile);
// 		if (fd != -1)
// 		{
// 			if (dup2(fd, STDIN_FILENO) == -1)
// 				perror("dup2 infile");
// 			close(fd);
// 		}
// 	}
// 	else if (shell->heredoc_delim)
// 		here_doc(shell);
// }

// void	out_redir(t_shell *minishell, t_token_type type)
// {
// 	int	fd;

// 	if (minishell->outfile)
// 	{
// 		fd = open_outfile(minishell->outfile, type);
// 		if (fd != -1)
// 		{
// 			if (dup2(fd, STDOUT_FILENO) == -1)
// 				perror("dup2 outfile");
// 			close(fd);
// 		}
// 	}
// }

// void	redirs(t_shell *minishell, t_token_type out_type)
// {
// 	in_redir(minishell);
// 	out_redir(minishell, out_type);
// }
