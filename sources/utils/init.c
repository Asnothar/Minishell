


#include "../../header/minishell.h"

t_shell	*init_shell(char **envp)
{
	t_shell *shell;

	shell = malloc(sizeof(t_shell));
	if (!shell)
		return (NULL);
	shell->envp = init_env_from_envp(envp);
	if (!shell->envp)
	{
		free(shell);
		return (NULL);
	}
	shell->input = NULL;
	shell->tokens = NULL;
	shell->heredoc_delim = NULL;
	shell->isbuiltin = 0;
	shell->last_exit_status = 0;
	return (shell);
}

t_shell	*start_init(char **envp)
{
	t_shell	*shell;

	shell = init_shell(envp);
	if (!shell)
	{
		perror("Erreur d'initialisation du shell");
		exit(EXIT_FAILURE);
	}
	return (shell);
}
