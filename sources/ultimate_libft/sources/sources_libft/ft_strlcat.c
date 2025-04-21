/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaufil <abeaufil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 13:32:42 by abeaufil          #+#    #+#             */
/*   Updated: 2025/03/19 17:39:01 by abeaufil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/ultimate_libft.h"

// Concatène une chaîne source à une destination en respectant une taille limite
// et retourne la longueur totale de la chaîne résultante.
size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	i;

	dst_len = 0;
	while (dst[dst_len])
		dst_len++;
	src_len = 0;
	while (src[src_len])
		src_len++;
	if (size <= dst_len)
		return (size + src_len);
	i = 0;
	while (i < (size - dst_len - 1) && src[i] != '\0')
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = '\0';
	return (dst_len + src_len);
}

// int	main(void)
// {
// 	char		dest[5] = "Salut";
// 	const char	*src = " Boloss!";
// 	size_t		result;

// 	result = ft_strlcat(dest, src, sizeof(dest));
// 	printf("Chaîne résultante : %s\n", dest);
// 	printf("Longueur théorique : %zu\n", result);
// 	return (0);
// }
