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
	int	i;

	if (minishell->cmds && minishell->cmds->args[1])
	{
		err_message("minishell: ", minishell->cmds->args[1],
			": No such file or directory\n");
		minishell->last_exit_status = 1;
		return ;
	}
	i = 0;
	while (minishell->envp[i])
	{
		ft_putstr_fd(minishell->envp[i], 1);
		write(1, "\n", 1);
		i++;
	}
	minishell->last_exit_status = 0;
}
