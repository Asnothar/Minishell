#include "../header/minishell.h"

int	main(int argc, char **argv, char **envp)
{
	char		*line;
	t_shell		*shell;

	(void)argc;
	(void)argv;
	shell = start_init(envp);
	setup_signals();
	while (1)
	{
		line = readline(BLUE "minishell> " RESET);
		if (!line)
		{
			write(2, "exit\n", 5);
			break ;
		}
		if (*line)
			add_history(line);
		shell->tokens = tokenize_input(line);
		if (!shell->tokens)
		{
			free(line);
			continue ;
		}
		parse(shell);
		print_debug_info(line, shell->tokens);
		free(line);
		free_token_list(shell->tokens);
		shell->tokens = NULL;
	}
	free_shell(shell);
	return (0);
}
