/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaufil <abeaufil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 13:13:53 by abeaufil          #+#    #+#             */
/*   Updated: 2025/03/19 17:40:03 by abeaufil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/ultimate_libft.h"

// Recherche la dernière occurrence d'un caractère dans une chaîne
// et retourne son adresse.
char	*ft_strrchr(const char *s, int c)
{
	char	*result;
	char	ch;
	size_t	i;

	result = NULL;
	ch = (char)c;
	i = 0;
	while (s[i])
	{
		if (s[i] == ch)
		{
			result = (char *)&s[i];
		}
		i++;
	}
	if (ch == '\0')
	{
		return ((char *)&s[i]);
	}
	return (result);
}

// int	main(void)
// {
// 	const char	*str;
// 	char		c;
// 	char		*result;
// 	char		*fonction;

// 	str = "Bonjour tout le monde";
// 	c = 't';
// 	result = ft_strrchr(str, c);
// 	fonction = strrchr(str, c);

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
