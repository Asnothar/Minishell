/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaufil <abeaufil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 11:35:33 by abeaufil          #+#    #+#             */
/*   Updated: 2025/03/19 18:35:39 by abeaufil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/ultimate_libft.h"

// Remplit les n premiers octets de la zone mémoire pointée par s avec
// des zéros.
void	ft_bzero(void *s, size_t n)
{
	unsigned char	*str;
	size_t			i;

	str = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		str[i] = '\0';
		i++;
	}
}

// int	main(void)
// {
// 	unsigned char str[] = "abcdef";
// 	size_t	n;

// 	n = 5;
// 	bzero (str, n);
// 	printf ("%p\n", (char *)str);
// 	ft_bzero (str, n);
// 	printf ("%p\n", (char *)str);
// }
