/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaufil <abeaufil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 16:29:46 by abeaufil          #+#    #+#             */
/*   Updated: 2025/03/19 17:39:54 by abeaufil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/ultimate_libft.h"

// Recherche la première occurrence d'une sous-chaîne dans une autre,
// en limitant la recherche à len caractères.
char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if (*little == '\0')
	{
		return ((char *)big);
	}
	i = 0;
	while ((i < len) && (big[i]))
	{
		if (big[i] == little[0])
		{
			j = 0;
			while ((little[j]) && ((i + j) < len) && (big[i + j] == little[j]))
			{
				j++;
			}
			if (!little[j])
			{
				return ((char *)(big + i));
			}
		}
		i++;
	}
	return (NULL);
}

// int	main(void)
// {
// 	char	*string1 = "Bonjour tout le monde";
// 	char	*string2 = "tout";
// 	size_t	length = 15;

// 	printf("%s\n", ft_strnstr(string1, string2, length));
// 	printf("%s\n", strnstr(string1, string2, length));

// 	return (0);
// }
