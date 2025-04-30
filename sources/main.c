/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaufil <abeaufil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 17:38:01 by abeaufil          #+#    #+#             */
/*   Updated: 2025/04/30 17:31:27 by abeaufil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	return ("WORD");
}

void	print_debug_info(char *line, char **tokens)
{
	int				i;
	t_token_type	type;

	printf("---------- Input ----------\n");
	if (line)
		printf("[%s]\n", line);
	else
		printf("[NULL]\n");
	printf("---------- Tokens ----------\n");
	if (tokens)
	{
		i = 0;
		while (tokens[i])
		{
			type = get_token_type(tokens[i]);
			printf("Token[%d]: [%s] (%s)\n", i, tokens[i], get_token_type_str(type));
			i++;
		}
	}
	else
		printf("No tokens\n");
	printf("---------- END ----------\n\n\n");
}

int	main(int argc, char **argv, char **envp)
{
	char	*line;
	char	**tokens;

	(void)argc;
	(void)argv;
	(void)envp;
	start_init();
	setup_signals();
	while (1)
	{
		line = readline("minishell> ");
		if (!line)
		{
			write(1, "exit\n", 5);
			break ;
		}
		tokens = tokenize_input(line);
		print_debug_info(line, tokens);
		if (*line)
			add_history(line);
		if (check_syntax(line))
		{
			free(line);
			continue ;
		}
		if (strcmp(line, "exit") == 0)
		{
			free(line);
			break ;
		}
		free(line);
	}
	return (0);
}
