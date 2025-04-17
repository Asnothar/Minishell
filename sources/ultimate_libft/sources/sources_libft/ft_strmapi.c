/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaufil <abeaufil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 18:18:34 by abeaufil          #+#    #+#             */
/*   Updated: 2025/03/19 18:40:37 by abeaufil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/ultimate_libft.h"

// Applique une fonction à chaque caractère d'une chaîne
// et retourne une nouvelle chaîne modifiée.
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t			i;
	size_t			len;
	char			*result;

	if (!s || !f)
		return (NULL);
	len = ft_strlen(s);
	result = (char *)malloc((len + 1) * sizeof(char));
	if (result == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		result[i] = f(i, s[i]);
		i++;
	}
	result[i] = '\0';
	return (result);
}

// int	main(void)
// {
// 	const char	*original = "hello world";
// 	char		*result;

// 	result = ft_strmapi(original, ft_toupper_bis);
// 	if (result == NULL)
// 	{
// 		printf("Erreur d'allocation\n");
// 		return (1);
// 	}
// 	printf("originale : %s\n", original);
// 	printf("transformee : %s\n", result);
// 	free(result);
// 	return (0);
// }