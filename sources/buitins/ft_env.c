/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjupille <sjupille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 17:47:30 by sjupille          #+#    #+#             */
/*   Updated: 2025/05/01 18:00:47 by sjupille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minishell.h"

void	ft_env(t_shell *minishell)
{
	t_env	*env;

	if (minishell->cmds && minishell->cmds->args[1])
	{
		err_message("minishell: ", minishell->cmds->args[1],
			": No such file or directory\n");
		minishell->last_exit_status = 1;
		return ;
	}
	env = minishell->envp;
	while (env)
	{
		if (env->value)
		{
			ft_putstr_fd(env->key, 1);
			write(1, "=", 1);
			ft_putstr_fd(env->value, 1);
			write(1, "\n", 1);
		}
		env = env->next;
	}
	minishell->last_exit_status = 0;
}
