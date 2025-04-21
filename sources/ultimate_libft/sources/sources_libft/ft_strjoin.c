/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaufil <abeaufil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 16:46:58 by abeaufil          #+#    #+#             */
/*   Updated: 2025/03/19 17:38:55 by abeaufil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/ultimate_libft.h"

// Concatène deux chaînes de caractères en une nouvelle chaîne
// allouée dynamiquement.
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	size_t	len1;
	size_t	len2;
	size_t	i;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	result = (char *)malloc((len1 + len2 + 1) * sizeof(char));
	if (!result)
		return (NULL);
	i = 0;
	while (*s1)
		result[i++] = *s1++;
	while (*s2)
		result[i++] = *s2++;
	result[i] = '\0';
	return (result);
}

// int	main(void)
// {
// 	char	str1[100];
// 	char	str2[100];
// 	char	*result;

// 	printf("Entrez la première chaîne : ");
// 	fgets(str1, sizeof(str1), stdin);
// 	str1[strcspn(str1, "\n")] = '\0';
// 	printf("Entrez la deuxième chaîne : ");
// 	fgets(str2, sizeof(str2), stdin);
// 	str2[strcspn(str2, "\n")] = '\0';
// 	result = ft_strjoin(str1, str2);
// 	if (result != NULL)
// 	{
// 		printf("Résultat de la concaténation : %s\n", result);
// 		free(result);
// 	}
// 	else
// 		printf("Erreur lors de la concaténation des chaînes.\n");
// 	return (0);
// }
