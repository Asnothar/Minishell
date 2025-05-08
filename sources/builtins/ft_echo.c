<<<<<<< HEAD
// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   ft_echo.c                                          :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: sjupille <sjupille@student.42.fr>          +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2025/05/05 11:39:51 by sjupille          #+#    #+#             */
// /*   Updated: 2025/05/05 14:33:39 by sjupille         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */
=======

>>>>>>> seb

// #include "../../header/minishell.h"

// static int	check_newline(char *str)
// {
// 	int	i;

// 	if (!str || str[0] != '-' || str[1] != 'n')
// 		return (0);
// 	i = 2;
// 	while (str[i] == 'n')
// 		i++;
// 	return (str[i] == '\0');
// }

// void	ft_echo(t_shell *minishell)
// {
// 	t_cmd	*cmd = minishell->cmds;
// 	int		i = 1;
// 	int		no_newline = 0;
// 	char	**args = cmd->args;

// 	while (args[i] && check_newline(args[i]))
// 	{
// 		no_newline = 1;
// 		i++;
// 	}
// 	while (args[i])
// 	{
// 		ft_putstr_fd(args[i], 1);
// 		if (args[i + 1])
// 			write(1, " ", 1);
// 		i++;
// 	}
// 	if (!no_newline)
// 		write(1, "\n", 1);
// 	minishell->last_exit_status = 0;
// }

