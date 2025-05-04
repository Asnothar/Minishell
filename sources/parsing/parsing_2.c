/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaufil <abeaufil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 16:43:48 by abeaufil          #+#    #+#             */
/*   Updated: 2025/04/29 15:43:33 by abeaufil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minishell.h"

void	err_message(char *message1, char *message2, char *message3)
{
	write(2, message1, ft_strlen(message1));
	write(2, message2, ft_strlen(message2));
	write(2, message3, ft_strlen(message3));
}

