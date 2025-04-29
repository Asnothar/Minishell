/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaufil <abeaufil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 16:11:31 by abeaufil          #+#    #+#             */
/*   Updated: 2025/04/29 16:25:09 by abeaufil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minishell.h"

char	*handle_quotes(const char *line, size_t *i, size_t len)
{
	char	quote;
	size_t	start;
	char	*token;

	quote = line[*i];
	start = ++(*i);
	while (*i < len && line[*i] != quote)
		(*i)++;
	token = strndup(&line[start], *i - start);
	if (*i < len)
		(*i)++;
	return (token);
}

char	*handle_special_characters(const char *line, size_t *i)
{
	char	*token;

	if ((line[*i] == '>' || line[*i] == '<') && line[*i + 1] == line[*i])
	{
		token = strndup(&line[*i], 2);
		*i += 2;
		return (token);
	}
	else
	{
		token = strndup(&line[*i], 1);
		(*i)++;
		return (token);
	}
}

char	**initialize_tokens(size_t len)
{
	char	**tokens;

	tokens = malloc(sizeof(char *) * (len + 1));
	if (!tokens)
		return (NULL);
	return (tokens);
}

char	*process_token(const char *line, size_t *i, size_t len)
{
	size_t	start;

	if (line[*i] == '"' || line[*i] == '\'')
		return (handle_quotes(line, i, len));
	else if (strchr("|<>", line[*i]))
		return (handle_special_characters(line, i));
	else
	{
		start = *i;
		while (*i < len && !isspace(line[*i]) && !strchr("|<>\"'", line[*i]))
			(*i)++;
		return (strndup(&line[start], *i - start));
	}
}

char	**tokenize_input(const char *line)
{
	size_t	i;
	size_t	j;
	size_t	len;
	char	**tokens;

	i = 0;
	j = 0;
	len = strlen(line);
	tokens = initialize_tokens(len);
	if (!tokens)
		return (NULL);
	while (i < len)
	{
		i = skip_whitespaces(line, i, len);
		tokens[j] = process_token(line, &i, len);
		j++;
	}
	tokens[j] = NULL;
	return (tokens);
}
