/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaufil <abeaufil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 17:38:01 by abeaufil          #+#    #+#             */
/*   Updated: 2025/05/08 13:52:43 by abeaufil         ###   ########.fr       */
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

	printf("\n---------- Input ----------\n");
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
	printf("---------- END ----------\n\n\n");
}

int	main(int argc, char **argv, char **envp)
{
	char		*line;
	t_token		*tokens = NULL;

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
			if (tokens)
				free_token_list(tokens);
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
			free_token_list(tokens);
			continue ;
		}
		if (strcmp(line, "exit") == 0)
		{
			free_token_list(tokens);
			free(line);
			break ;
		}
		free(line);
		free_token_list(tokens);
	}
	return (0);
}
