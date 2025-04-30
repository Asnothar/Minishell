/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaufil <abeaufil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 13:41:18 by abeaufil          #+#    #+#             */
/*   Updated: 2025/04/30 17:56:40 by abeaufil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minishell.h"

t_cmd	*init_cmd(void)
{
	t_cmd	*cmd;

	cmd = malloc(sizeof(t_cmd));
	if (!cmd)
		return (NULL);
	cmd->args = NULL;
	cmd->infile = NULL;
	cmd->outfile = NULL;
	cmd->heredoc_delim = NULL;
	cmd->pipe_fd[0] = -1;
	cmd->pipe_fd[1] = -1;
	cmd->next = NULL;
	return (cmd);
}

t_shell	*init_shell(void)
{
	t_shell	*shell;

	shell = malloc(sizeof(t_shell));
	if (!shell)
		return (NULL);
	shell->envp = NULL;
	shell->input = NULL;
	shell->cmds = NULL;
	shell->last_exit_status = 0;
	return (shell);
}

t_env	*init_env(void)
{
	t_env	*env;

	env = malloc(sizeof(t_env));
	if (!env)
		return (NULL);
	env->key = NULL;
	env->value = NULL;
	env->next = NULL;
	return (env);
}

void	start_init(void)
{
	t_shell	*shell;
	t_env	*env;

	shell = init_shell();
	if (!shell)
	{
		perror("Erreur d'initialisation du shell");
		exit(EXIT_FAILURE);
	}
	env = init_env();
	if (!env)
	{
		perror("Erreur d'initialisation de l'environnement");
		free(shell);
		exit(EXIT_FAILURE);
	}
	free(shell);
	free(env);
}
