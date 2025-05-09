


#include "../../header/minishell.h"

int	parse(t_shell *shell)
{
	if (!shell || !shell->tokens)
		return (1);
	return (command_type(shell));
}

int	command_type(t_shell *shell)
{
	char	*cmd;

	cmd = shell->tokens->value;
	if (!cmd)
		return (1);
	// if (ft_strncmp(cmd, "pwd", 4) == 0)
	// 	return (ft_pwd(shell));
	// if (ft_strncmp(cmd, "cd", 3) == 0)
	// 	return (ft_cd(shell));
	// if (ft_strncmp(cmd, "echo", 5) == 0)
	// 	return (ft_echo(shell));
	// if (ft_strncmp(cmd, "env", 4) == 0)
	// 	return (ft_env(shell));
	// if (ft_strncmp(cmd, "exit", 5) == 0)
	// 	return (ft_exit(shell));
	// if (ft_strncmp(cmd, "export", 7) == 0)
	// 	return (ft_export(shell));
	// if (ft_strncmp(cmd, "unset", 6) == 0)
	// 	return (ft_unset(shell));
	// if (ft_strncmp(cmd, "./", 2) == 0)
	// 	return (ft_executable(shell));
	// return (launch_system_command(shell));
	return (0);
}

