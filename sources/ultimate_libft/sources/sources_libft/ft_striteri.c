/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaufil <abeaufil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 13:54:18 by abeaufil          #+#    #+#             */
/*   Updated: 2025/03/19 18:39:00 by abeaufil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/ultimate_libft.h"

void	ft_toupper_bis(unsigned int i, char *c)
{
	i = 32;
	if (*c >= 'a' && *c <= 'z')
		*c -= i;
}

// Applique une fonction à chaque caractère d'une chaîne, en passant son
// index et une référence au caractère.
void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t			i;

	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}
// int	main(void)
// {
// 	char	str[] = "hello world";

// 	printf("Avant ft_striteri : %s\n", str);
// 	ft_striteri(str, ft_toupper_bis);
// 	printf("Après ft_striteri : %s\n", str);

// 	return (0);
// }