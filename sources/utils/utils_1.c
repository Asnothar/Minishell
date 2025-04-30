/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaufil <abeaufil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 15:39:30 by abeaufil          #+#    #+#             */
/*   Updated: 2025/04/30 17:28:54 by abeaufil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minishell.h"

int	skip_whitespaces(const char *str, int i, int len)
{
	while (i < len && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
			|| str[i] == '\r' || str[i] == '\v' || str[i] == '\f'))
		i++;
	return (i);
}

void	print_tokens(char **tokens)
{
	int	i;

	i = 0;
	while (tokens[i])
	{
		printf("[%s]\n", tokens[i]);
		i++;
	}
}

void	free_cmd(t_cmd *cmd)
{
	if (cmd)
	{
		free(cmd->args);
		free(cmd->infile);
		free(cmd->outfile);
		free(cmd->heredoc_delim);
		free(cmd);
	}
}
