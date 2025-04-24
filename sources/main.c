/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaufil <abeaufil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 17:38:01 by abeaufil          #+#    #+#             */
/*   Updated: 2025/04/24 18:09:07 by abeaufil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

int check_quotes(char *line)
{
	int i = 0;
	int single_quote = 0;
	int double_quote = 0;

	while (line[i])
	{
		if (line[i] == '\'' && double_quote == 0)
			single_quote = !single_quote;
		else if (line[i] == '\"' && single_quote == 0)
			double_quote = !double_quote;
		i++;
	}
	return (single_quote || double_quote);
}

int check_pipe(char *line)
{
	int i = 0;
	int pipe_count = 0;

	while (line[i])
	{
		if (line[i] == '|')
			pipe_count++;
		i++;
	}
	return (pipe_count);
}

int check_redirection(char *line)
{
	int i = 0;
	int redirection_count = 0;

	while (line[i])
	{
		if (line[i] == '>' || line[i] == '<')
			redirection_count++;
		i++;
	}
	return (redirection_count);
}

int check_special_characters(char *line)
{
	int i = 0;

	while (line[i])
	{
		if (line[i] == ';' || line[i] == '\\')
			return (1);
		i++;
	}
	return (0);
}

int check_syntax(char *line)
{
	if (check_quotes(line))
		return (write(2, "Error: Unmatched quotes\n", 24), 1);
	if (check_pipe(line) > 1)
		return (write(2, "Error: Too many pipes\n", 23), 1);
	if (check_redirection(line) > 2)
		return (write(2, "Error: Too many redirections\n", 31), 1);
	if (check_special_characters(line))
		return (write(2, "Error: Invalid special characters\n", 34), 1);
	if (line[0] == '|' || line[0] == ';' || line[0] == '>' || line[0] == '<')
		return (write(2, "Error: Command cannot start with a pipe or semicolon or a redirection\n", 70), 1);
	if (line[0] == '\n')
		return (write(2, "Error: Empty command\n", 21), 1);
	return (0);
}

int main(int argc, char **argv, char **envp)
{
	char *line;

	(void)argc;
	(void)argv;
	line = readline("minishell> ");
	if (line == NULL)
	{
		perror("readline");
		exit(EXIT_FAILURE);
	}
	printf("You entered: %s", line);
	if (check_syntax(line))
	{
		free(line);
		return (1);
	}
	return (0);
}
