/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaufil <abeaufil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 14:16:30 by abeaufil          #+#    #+#             */
/*   Updated: 2025/03/19 18:41:48 by abeaufil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/ultimate_libft.h"

// Convertit une lettre majuscule en minuscule si elle en est une, sinon
// elle renvoie le caractère inchangé.
int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
	{
		return (c + 32);
	}
	return (c);
}

// int	main(void)
// {
// 	char	c;

// 	c = 'B';
// 	printf ("Caractère d'origine : %c\n", c);

// 	printf ("Caractère en minuscule : %c\n", ft_tolower(c));

// 	return (0);
// }