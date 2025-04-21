/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaufil <abeaufil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 16:27:12 by abeaufil          #+#    #+#             */
/*   Updated: 2025/03/19 18:39:33 by abeaufil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/ultimate_libft.h"

// Copie une chaîne source dans une destination avec une taille limite et
// retourne la longueur totale de la source.
size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	unsigned int	i;
	unsigned int	j;

	j = 0;
	while (src[j])
	{
		j++;
	}
	i = 0;
	if (size > 0)
	{
		while (src[i] && i < size - 1)
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (j);
}

// int	main(void)
// {
// 	char str[] = "testo";
// 	char strDest[5];
// 	int r = ft_strlcpy(strDest, str, 2);

// 	printf("%s\n", strDest); 
// 	printf("%d", r);
// }