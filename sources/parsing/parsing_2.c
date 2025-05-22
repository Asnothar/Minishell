#include "../../header/minishell.h"

void	err_message(char *message1, char *message2, char *message3)
{
	write(2, message1, ft_strlen(message1));
	write(2, message2, ft_strlen(message2));
	write(2, message3, ft_strlen(message3));
}

int	check_first_token_pipe(t_token *tokens)
{
	if (!tokens)
		return (1);
	if (tokens->value && tokens->value[0] == '|')
	{
		write(2, "syntax error near unexpected token `|'\n", 39);
		return (1);
	}
	return (0);
}

int	check_or_operator(t_token *tokens)
{
	if (!tokens)
		return (1);
	while (tokens)
	{
		if (tokens->value && tokens->value[0] == '|')
		{
			if (tokens->next && tokens->next->value
				&& tokens->next->value[0] == '|')
			{
				write(2, "syntax error near unexpected token `||'\n", 40);
				return (1);
			}
		}
		tokens = tokens->next;
	}
	return (0);
}

int	check_redir_syntaxe(t_token *tokens)
{
	t_token	*next;

	if (!tokens)
		return (1);
	while (tokens)
	{
		if (tokens->value
			&& (tokens->value[0] == '<' || tokens->value[0] == '>'))
		{
			next = tokens->next;
			if (!next || !next->value || next->value[0] == '<'
				|| next->value[0] == '>' || next->value[0] == '|')
			{
				write(2, "syntax error near unexpected token `", 37);
				if (!next || !next->value)
					write(2, "newline", 7);
				else
					write(2, next->value, 1);
				write(2, "'\n", 2);
				return (1);
			}
		}
		tokens = tokens->next;
	}
	return (0);
}
