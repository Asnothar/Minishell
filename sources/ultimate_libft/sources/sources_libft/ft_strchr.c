/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaufil <abeaufil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 11:42:40 by abeaufil          #+#    #+#             */
/*   Updated: 2025/03/19 18:38:43 by abeaufil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/ultimate_libft.h"

// Recherche la première occurrence d'un caractère dans une chaîne
// et retourne son adresse.
char	*ft_strchr(const char *s, int c)
{
	char	ch;
	size_t	i;

	ch = (char)c;
	i = 0;
	while (s[i])
	{
		if (s[i] == ch)
		{
			return ((char *)(s + i));
		}
		i++;
	}
	if (ch == '\0')
	{
		return ((char *)(s + i));
	}
	return (NULL);
}

// int	main(void)
// {
// 	const char	*str;
// 	char		c;
// 	char		*result;
// 	char		*fonction;

// 	str = "Bonjour tout le monde";
// 	c = 'a';
// 	result = ft_strchr(str, c);
// 	fonction = strchr(str, c);

// 	if (result)
// 	{
// 		printf("Le caractère '%c' a été trouvé ici : %s\n", c, result);
// 		printf("Le caractère '%c' a été trouvé ici : %s\n", c, fonction);
// 	}
// 	else
// 	{
// 		printf("Le caractère '%c' n'a pas été trouvé\n", c);
// 	}
// 	return (0);
// }
