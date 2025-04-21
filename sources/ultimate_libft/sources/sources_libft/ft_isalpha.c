/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaufil <abeaufil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 15:25:45 by abeaufil          #+#    #+#             */
/*   Updated: 2025/03/19 17:53:09 by abeaufil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/ultimate_libft.h"

// Vérifie si un caractère est une lettre de l'alphabet, qu'elle
// soit majuscule ou minuscule.
int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	return (0);
}

// int	main(void)
// {
// 	int	test_char;

// 	test_char = '0';
// 	if (ft_isalpha(test_char))
// 		printf("'%c' est alpha.\n", test_char);
// 	else
// 		printf("'%c' n'est pas alpha.\n", test_char);
// 	return (0);
// }
