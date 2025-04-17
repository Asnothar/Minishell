/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaufil <abeaufil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 16:22:39 by abeaufil          #+#    #+#             */
/*   Updated: 2025/04/07 17:40:08 by abeaufil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/pipex.h"

void	free_tab(char **str)
{
	int	i;

	if (!str)
		return ;
	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	free_all(char **str1, char **str2)
{
	if (str1)
		free_tab(str1);
	if (str2)
		free_tab(str2);
}

void	exit_free(char **path, char **cmd, int error_code, int exit_code)
{
	free_all(path, cmd);
	if (error_code == 1)
		write(2, "Command not found\n", 18);
	if (exit_code == 1)
		exit(1);
}
