

extern int	g_exit_status;

void	cd_absolute(t_minishell *minishell)
{
	char	*old;
	char	*new;
	char	path[PATH_MAX];
	char	path2[PATH_MAX];

	old = getcwd(path, PATH_MAX);
	chdir(minishell->cmd[1]);
	new = getcwd(path2, PATH_MAX);
	ft_pwd(minishell, old, new);
	g_exit_status = 0;
}

void	cd_home(t_minishell *minishell)
{
	t_env	*start;
	char	*old;
	char	*new;
	char	path[PATH_MAX];
	char	path2[PATH_MAX];

	start = minishell->envm;
	old = getcwd(path, PATH_MAX);
	while (start)
	{
		if (ft_strcmp(start->key, "HOME") == 0)
		{
			chdir (start->value);
			break ;
		}
		start = start->next;
	}
	new = getcwd(path2, PATH_MAX);
	ft_pwd(minishell, old, new);
}
