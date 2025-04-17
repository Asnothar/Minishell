/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaufil <abeaufil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 10:36:40 by abeaufil          #+#    #+#             */
/*   Updated: 2025/03/19 17:52:00 by abeaufil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/ultimate_libft.h"

// Vérifie si un caractère est un chiffre, c'est-à-dire s'il est compris
// entre '0' et '9'.
int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

// int	main(void)
// {
// 	int	test_char;

// 	test_char = '0';
// 	if (ft_isdigit(test_char))
// 		printf("'%c' est digit.\n", test_char);
// 	else
// 		printf("'%c' n'est pas digit.\n", test_char);
// 	return (0);
// }
