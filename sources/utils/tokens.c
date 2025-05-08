/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaufil <abeaufil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 16:11:31 by abeaufil          #+#    #+#             */
/*   Updated: 2025/05/01 16:43:39 by abeaufil         ###   ########.fr       */
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

t_token	*create_token_node(char *value)
{
	t_token	*node;

	node = malloc(sizeof(t_token));
	if (!node)
		return (NULL);
	node->value = value;
	node->next = NULL;
	return (node);
}

void	add_token_back(t_token **head, t_token *new)
{
	t_token	*tmp;

	if (!*head)
	{
		*head = new;
		return ;
	}
	tmp = *head;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
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

t_token	*tokenize_input(const char *line)
{
	size_t	i;
	size_t	len;
	char	*token_str;
	t_token	*token_list;
	t_token	*new_node;

	i = 0;
	len = strlen(line);
	token_list = NULL;
	while (i < len)
	{
		i = skip_whitespaces(line, i, len);
		if (i >= len)
			break ;
		token_str = process_token(line, &i, len);
		if (!token_str)
			continue ;
		new_node = create_token_node(token_str);
		if (!new_node)
			continue ;
		add_token_back(&token_list, new_node);
	}
	return (token_list);
}
