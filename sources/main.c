/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaufil <abeaufil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 17:38:01 by abeaufil          #+#    #+#             */
/*   Updated: 2025/04/29 16:17:35 by abeaufil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

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
		printf("---------- Input ----------\n");
		printf("[%s]\n", line);
		tokens = tokenize_input(line);
		printf("---------- Tokens ----------\n");
		print_tokens(tokens);
		if (!line)
		{
			write(1, "exit\n", 5);
			break ;
		}
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
		printf("---------- END ----------\n");
		printf("\n");
		printf("\n");
	}
	return (0);
}
