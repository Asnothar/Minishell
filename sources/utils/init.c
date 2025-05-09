


#include "../../header/minishell.h"

t_env	*init_env_from_envp(char **envp)
{
	t_env	*head;
	t_env	*current;
	int		i;

	i = 0;
	head = NULL;
	while (envp[i])
	{
		t_env *new = malloc(sizeof(t_env));
		if (!new)
			return (NULL);
		new->key = ft_substr(envp[i], 0, ft_strchr(envp[i], '=') - envp[i]);
		new->value = ft_strdup(ft_strchr(envp[i], '=') + 1);
		new->next = NULL;
		if (!head)
			head = new;
		else
		{
			current = head;
			while (current->next)
				current = current->next;
			current->next = new;
		}
		i++;
	}
	return (head);
}

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
