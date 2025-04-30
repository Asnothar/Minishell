/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaufil <abeaufil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 16:43:48 by abeaufil          #+#    #+#             */
/*   Updated: 2025/04/30 17:40:09 by abeaufil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minishell.h"

int	check_quotes(char *line)
{
	int	i;
	int	single_quote;
	int	double_quote;

	i = 0;
	single_quote = 0;
	double_quote = 0;
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

int	check_pipe(char *line)
{
	int	i;
	int	pipe_count;

	i = 0;
	pipe_count = 0;
	while (line[i])
	{
		if (line[i] == '|')
			pipe_count++;
		i++;
	}
	return (pipe_count);
}

int	check_redirection(char *line)
{
	int	i;
	int	redirection_count;

	i = 0;
	redirection_count = 0;
	while (line[i])
	{
		if (line[i] == '>' || line[i] == '<')
			redirection_count++;
		i++;
	}
	return (redirection_count);
}

int	check_special_characters(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == ';' || line[i] == '\\')
			return (1);
		i++;
	}
	return (0);
}

int	check_syntax(char *line)
{
	if (check_quotes(line))
		return (write(2, "Error: Unmatched quotes\n", 24), 1);
	if (check_pipe(line) > 1)
		return (write(2, "Error: Too many pipes\n", 22), 1);
	if (check_redirection(line) > 2)
		return (write(2, "Error: Too many redirections\n", 29), 1);
	if (check_special_characters(line))
		return (write(2, "Error: Invalid special characters\n", 34), 1);
	if (line[0] == '|' || line[0] == ';' || line[0] == '>' || line[0] == '<')
		return (write(2, "Error: Command cannot start with a pipe or semicolon or a redirection\n", 70), 1);
	if (line[0] == '\n')
		return (write(2, "Error: Empty command\n", 21), 1);
	return (0);
}
