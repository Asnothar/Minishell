/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaufil <abeaufil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 16:19:01 by abeaufil          #+#    #+#             */
/*   Updated: 2025/03/19 18:37:29 by abeaufil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/ultimate_libft.h"

// compare les n premiers octets de deux zones mémoire et retourne la 
// différence entre les premiers octets différents.
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && *(unsigned char *)(s1 + i) == *(unsigned char *)(s2 + i))
		i++;
	if (i < n)
		return (*(unsigned char *)(s1 + i) - *(unsigned char *)(s2 + i));
	return (0);
}

// int	main(void)
// {
// 	char	*s1;
// 	char	*s2;

// 	s1 = "aaaaaaa";
// 	s2 = "aaawaaa";
// 	printf("ft_memcmp :	%d\n", ft_memcmp(s1, s2, 20));
// 	printf("memcmp :	%d\n", memcmp(s1, s2, 20));
// 	return (0);
// }