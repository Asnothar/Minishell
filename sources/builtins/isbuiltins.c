

#include "../../header/minishell.h"

int	is_builtin2(t_shell *minishell)
{
	if (ft_strcase(minishell->cmds->args[0], "unset") == 0)
	{
		if (minishell->cmds->args[1])
			ft_unset(minishell, minishell->cmds);
		return (1);
	}
	if (ft_strcase(minishell->cmds->args[0], "export") == 0)
	{
		if (minishell->cmds->args[1])
			ft_export(minishell);
		else
			export_print(minishell->envp);
		return (1);
	}
	if (ft_strcmp(minishell->cmds->args[0], "/usr/bin/cd") == 0
		|| ft_strcmp(minishell->cmds->args[0], "cd") == 0)
	{
		ft_cd(minishell);
		return (1);
	}
	return (0);
}

int	is_builtin(t_shell *minishell, char **command)
{
	if (ft_strcase(command[0], "/bin/echo") == 0
		|| ft_strcase(command[0], "echo") == 0)
		ft_echo(command);
	else if (ft_strcmp(minishell->cmds->args[0], "exit") == 0)
		ft_exit(minishell, 1, 0);
	else if (ft_strcase(command[0], "/usr/bin/env") == 0
		|| ft_strcase(command[0], "env") == 0)
		ft_env(minishell);
	else if (ft_strcase(command[0], "/bin/pwd") == 0
		|| ft_strcase(command[0], "pwd") == 0)
		ft_pwd();
	else if (is_builtin2(minishell))
		return (1);
	else
		return (0);
	return (1);
}
