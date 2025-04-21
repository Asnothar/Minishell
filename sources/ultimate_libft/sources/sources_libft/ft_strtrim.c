/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaufil <abeaufil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 10:10:28 by abeaufil          #+#    #+#             */
/*   Updated: 2025/03/19 18:41:05 by abeaufil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/ultimate_libft.h"

static int	ft_isset(char c, const char *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

// Supprime les caractères spécifiés dans set au début
// et à la fin de la chaîne s1 et retourne la nouvelle chaîne résultante.
char	*ft_strtrim(char const *s1, char const *set)
{
	size_t			i;
	size_t			start;
	size_t			end;
	size_t			len;
	char			*new_str;

	start = 0;
	while (s1[start] && ft_isset(s1[start], set))
		start++;
	end = (ft_strlen(s1) - 1);
	while (end >= start && ft_isset(s1[end], set))
		end--;
	len = end - start + 1;
	new_str = (char *)malloc(sizeof(char) * (len + 1));
	if (new_str == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		new_str[i] = s1[start + i];
		i++;
	}
	new_str[len] = '\0';
	return (new_str);
}

// int	main(void)
// {
// 	const char	*str = "        abcdefghijklmno !        ";
// 	const char	*set = " ";
// 	char	*trimmed_str = ft_strtrim(str, set);

// 	if (trimmed_str)
// 	{
// 		printf("Chaine avant trim: '%s'\n", str);
// 		printf("Chaine apres trim:	 '%s'\n\n", trimmed_str);
// 		free(trimmed_str);
// 	}
// 	else
// 		printf("Memory allocation failed\n");
// 	return (0);
// }
