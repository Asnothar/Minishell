


#include "../header/minishell.h"

t_token_type	get_token_type(char *token)
{
	if (!token)
		return (WORD);
	if (token[0] == '|' && token[1] == '\0')
		return (PIPE);
	if (token[0] == '<' && token[1] == '\0')
		return (REDIR_IN);
	if (token[0] == '>' && token[1] == '\0')
		return (REDIR_OUT);
	if (token[0] == '<' && token[1] == '<' && token[2] == '\0')
		return (HERE_DOC);
	if (token[0] == '>' && token[1] == '>' && token[2] == '\0')
		return (APPEND);
	return (WORD);
}

char	*get_token_type_str(t_token_type type)
{
	if (type == PIPE)
		return ("PIPE");
	if (type == REDIR_IN)
		return ("REDIR_IN");
	if (type == REDIR_OUT)
		return ("REDIR_OUT");
	if (type == HERE_DOC)
		return ("HERE_DOC");
	if (type == APPEND)
		return ("APPEND");
	return ("WORD");
}

void	print_debug_info(char *line, t_token *tokens)
{
	int				i;
	t_token_type	type;

	printf("\033[33m\n---------- Input -----------\n");
	if (line)
		printf("[%s]\n", line);
	else
		printf("[NULL]\n");
	printf("---------- Tokens ----------\n");
	if (tokens)
	{
		i = 0;
		while (tokens)
		{
			type = get_token_type(tokens->value);
			printf("Token[%d]: [%s] (%s)\n", i, tokens->value, get_token_type_str(type));
			tokens = tokens->next;
			i++;
		}
	}
	else
		printf("No tokens\n");
	printf("----------- END ------------\033[0m\n\n\n");
}

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
		print_debug_info(line, shell->tokens);
		parse(shell);
		free(line);
		free_token_list(shell->tokens);
		shell->tokens = NULL;
	}
	free_shell(shell);
	return (0);
}


