


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
int	ft_strcase(char *str, char *with_whom)
{
	int		i;
	char	*str1;

	str1 = ft_strdup(str);
	i = 0;
	if (!str1)
		return (0);
	while (str1[i])
	{
		if (str1[i] >= 'A' && str1[i] <= 'Z')
			str1[i] += 32;
		i++;
	}
	i = ft_strcmp(str1, with_whom);
	free(str1);
	return (i);
}
