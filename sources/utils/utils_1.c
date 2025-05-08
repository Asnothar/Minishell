


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

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

void	free_token_list(t_token *head)
{
	t_token	*tmp;

	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp->value);
		free(tmp);
	}
}
