/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaufil <abeaufil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 17:38:01 by abeaufil          #+#    #+#             */
/*   Updated: 2025/04/30 11:41:04 by abeaufil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

void	print_debug_info(char *line, char **tokens)
{
	int	i;

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
			printf("Token[%d]: %s\n", i, tokens[i]);
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
