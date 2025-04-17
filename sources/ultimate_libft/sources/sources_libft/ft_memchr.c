/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaufil <abeaufil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 14:02:05 by abeaufil          #+#    #+#             */
/*   Updated: 2025/03/19 17:45:18 by abeaufil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/ultimate_libft.h"

// Recherche la première occurrence d'un caractère dans une zone mémoire
// et retourne un pointeur vers cette position.
void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	const unsigned char	*string;

	string = (const unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (string[i] == (unsigned char)c)
			return ((void *)&string[i]);
		i++;
	}
	return (NULL);
}

// int	main(void)
// {
// 	printf("%s\n", (char *) ft_memchr("testopi", 'z', 40));
// 	printf("%s\n", (char *) memchr("testopi", 'z', 40));
// 	return (0);
// }
