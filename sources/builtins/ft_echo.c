#include "../../header/minishell.h"

int	check_newline_token(t_token *token)
{
	char	*str;
	int		i;

	str = token->value;
	if (!str || str[0] != '-' || str[1] != 'n')
		return (0);
	i = 2;
	while (str[i] == 'n')
		i++;
	return (str[i] == '\0');
}

int	ft_echo(t_shell *minishell)
{
	t_token	*token;
	int		no_newline;

	token = minishell->tokens->next;
	no_newline = 0;
	while (token && check_newline_token(token))
	{
		no_newline = 1;
		token = token->next;
	}
	while (token)
	{
		ft_putstr_fd(token->value, 1);
		if (token->next)
			write(1, " ", 1);
		token = token->next;
	}
	if (!no_newline)
		write(1, "\n", 1);
	minishell->last_exit_status = 0;
	return (0);
}
