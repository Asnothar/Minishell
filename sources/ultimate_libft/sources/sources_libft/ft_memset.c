/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaufil <abeaufil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 13:22:07 by abeaufil          #+#    #+#             */
/*   Updated: 2025/03/19 18:37:49 by abeaufil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/ultimate_libft.h"

// Remplit une zone mémoire avec un caractère spécifié sur un nombre
// donné d'octets.
void	*ft_memset(void *s, int c, size_t n)
{
	char	*str;
	size_t	i;

	i = 0;
	str = (char *)s;
	while (i < n)
	{
		str[i] = (char)c;
		i++;
	}
	return ((void *) str);
}

// int	main(void)
// {
// 	char	buffer[10];

// 	printf ("%p\n", (char *)ft_memset (buffer, 'A', 9));
// 	ft_memset(buffer, 'A', 9);
// 	printf("%s\n", buffer);
// 	return (0);
// }
