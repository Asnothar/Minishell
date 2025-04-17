/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaufil <abeaufil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 18:02:40 by abeaufil          #+#    #+#             */
/*   Updated: 2025/03/19 17:44:41 by abeaufil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/ultimate_libft.h"

// Copie n octets de la source vers la destination et initialise le reste de
// la mémoire de la destination à zéro.
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned int	i;
	unsigned char	*dst;
	unsigned char	*source;

	dst = (unsigned char *)dest;
	source = (unsigned char *)src;
	i = 0;
	if (!dst && !src)
		return (NULL);
	while (i < n)
	{
		dst[i] = source[i];
		i++;
	}
	while (i < n)
	{
		dst[i] = '\0';
		i++;
	}
	return (dst);
}

// int	main(void)
// {
// 	char	source[] = "Bonjour";
// 	char	destination[20];

// 	printf("before: %s\n", destination);

// 	ft_memcpy(destination, source, strlen(source) + 1);
// 	memcpy(destination, source, strlen(source) + 1);

// 	printf("Destination : %s\n", destination);

// 	return (0);
// }
