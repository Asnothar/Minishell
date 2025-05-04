
static int	matrix_len(char **array)
{
	int	i = 0;

	if (!array || !*array)
		return (0);
	while (array[i])
		i++;
	return (i);
}

static int	check_newline(char *str)
{
	int	i = 0;

	if (!str || str[i] != '-' || str[i + 1] != 'n')
		return (0);
	i++; 

	while (str[++i] == 'n')
		;
	return (str[i] == '\0');
}

void	ft_echo(t_shell *minishell)
{
	t_cmd	*cmd = minishell->cmds;
	int		i = 1;
	int		flag = 0;
	char	**args = cmd->args;

	while (args[i] && check_newline(args[i]))
	{
		flag = 1;
		i++;
	}

	while (args[i])
	{
		ft_putstr_fd(args[i], 1);
		if (args[i + 1])
			write(1, " ", 1);
		i++;
	}

	if (!flag)
		write(1, "\n", 1);

	minishell->last_exit_status = 0;
}
