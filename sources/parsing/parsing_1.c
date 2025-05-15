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
	if (ft_strncmp(cmd, "pwd", 4) == 0)
		return (ft_pwd());
	// else if (ft_strncmp(cmd, "cd", 3) == 0)
	// 	return (ft_cd(shell));
	else if (ft_strncmp(cmd, "echo", 5) == 0)
		return (ft_echo(shell));
	else if (ft_strncmp(cmd, "env", 4) == 0)
		return (ft_env(shell));
	else if (ft_strncmp(cmd, "exit", 5) == 0)
		return (ft_exit(shell, 0, 0)); // NE PAS OUBLIER LE IS_IN_FORK ET LE PRINT
	// else if (ft_strncmp(cmd, "export", 7) == 0)
	// 	return (ft_export(shell));
	// else if (ft_strncmp(cmd, "unset", 6) == 0)
	// 	return (ft_unset(shell));
	// else if (ft_strncmp(cmd, "./", 2) == 0)
	// 	return (ft_executable(shell));
	else
		write(2, "Command not found\n", 18);
	return (0);
	// return (launch_system_command(shell));
}
