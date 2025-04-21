/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaufil <abeaufil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 14:18:23 by abeaufil          #+#    #+#             */
/*   Updated: 2025/03/19 18:36:18 by abeaufil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/ultimate_libft.h"

// Convertit une chaîne de caractères en un entier en gérant les espaces,
// les signes et les chiffres.
int	ft_atoi(const char *nptr)
{
	int	i;
	int	res;
	int	sign;

	res = 0;
	i = 0;
	sign = 1;
	while (nptr[i] == 32 || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		res = res * 10 + (nptr[i] - '0');
		i++;
	}
	return (res * sign);
}

/*int	main(void)
{
	char	str[] = " 	----+-+-+-+-+-12k34bub567";

	printf("ft_atoi : %d\n\n", ft_atoi(str));
	printf("atoi : %d\n\n", atoi(str));
	return (0);
}*/
