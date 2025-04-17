/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaufil <abeaufil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 13:42:10 by abeaufil          #+#    #+#             */
/*   Updated: 2025/03/19 18:41:53 by abeaufil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/ultimate_libft.h"

// Convertit une lettre minuscule en majuscule. Si le caractère n'est pas
// une minuscule, il est retourné tel quel.
int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}

// int	main(void)
// {
// 	char	c;

// 	c = 'B';
// 	printf ("Caractère d'origine : %c\n", c);

// 	printf ("Caractère en majuscule : %c\n", ft_toupper(c));

// 	return (0);
// }
