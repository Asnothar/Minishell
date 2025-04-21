/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaufil <abeaufil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 15:36:13 by abeaufil          #+#    #+#             */
/*   Updated: 2025/03/19 17:40:32 by abeaufil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/ultimate_libft.h"

// Extrait une sous-chaîne d'une chaîne donnée,
// en allouant dynamiquement la nouvelle portion.
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new_str;
	size_t	s_len;
	size_t	i;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		len = 0;
	else if (len > s_len - start)
		len = s_len - start;
	new_str = (char *)malloc((len + 1) * sizeof(char));
	if (!new_str)
		return (NULL);
	i = 0;
	while (i < len)
	{
		new_str[i] = s[start + i];
		i++;
	}
	new_str[len] = '\0';
	return (new_str);
}

// int	main(void)
// {
// 	char			str[] = "Hello, World!";
// 	unsigned int	start = 7;
// 	size_t			len = 5;
// 	char			*result = ft_substr(str, start, len);

// 	free(result);
// 	return (0);
// }
