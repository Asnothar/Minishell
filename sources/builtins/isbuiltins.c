

#include "../../header/minishell.h"

int	is_builtin2(t_minishell *minishell)
{
	if (ft_tolower(minishell->cmds[0], "unset") == 0)
	{
		if (minishell->cmds[1])
			unset(minishell, minishell->cmds);
		return (1);
	}
	if (ft_tolower(minishell->cmds[0], "export") == 0)
	{
		if (minishell->cmds[1])
			export(minishell);
		else
			export_print(minishell->envp);
		return (1);
	}
	if (ft_strcmp(minishell->cmds[0], "/usr/bin/cd") == 0
		|| ft_strcmp(minishell->cmds[0], "cd") == 0)
	{
		cd(minishell);
		return (1);
	}
	return (0);
}

int	is_builtin(t_shell *minishell, char **command)
{
	if (ft_tolower(command[0], "/bin/echo") == 0
		|| ft_tolower(command[0], "echo") == 0)
		echo(command);
	else if (ft_tolower(command[0], "/usr/bin/env") == 0
		|| ft_tolower(command[0], "env") == 0)
		env(minishell);
	else if (ft_tolower(command[0], "/bin/pwd") == 0
		|| ft_tolower(command[0], "pwd") == 0)
		pwd();
	else if (is_builtin2(minishell))
		return (1);
	else
		return (0);
	return (1);
}
