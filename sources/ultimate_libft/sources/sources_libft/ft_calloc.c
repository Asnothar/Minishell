/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaufil <abeaufil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 14:04:38 by abeaufil          #+#    #+#             */
/*   Updated: 2025/03/19 18:35:03 by abeaufil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/ultimate_libft.h"

// Alloue une zone mémoire de nmemb * size octets, initialise chaque octet à
// 0, et retourne un pointeur vers cette zone, ou NULL en cas d’échec.
void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t			total_size;
	unsigned char	*ptr;
	size_t			i;

	if (nmemb * size > (size_t) - 1)
		return (NULL);
	total_size = nmemb * size;
	ptr = malloc(total_size);
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < total_size)
	{
		ptr[i] = 0;
		i++;
	}
	return (ptr);
}

// int main(void)
// {
// 	int *numbers;
// 	size_t n = 5;
// 	size_t i;

// 	numbers = (int *)ft_calloc(n, sizeof(int));
// 	if (numbers == NULL)
// 	{
// 		printf("Echec de l'allocation de memoire\n");
// 		return 1;
// 	}
// 	printf("Valeurs initiales :\n");
// 	i = 0;
// 	while (i < n)
// 	{
// 		printf("%d ", numbers[i]);
// 		i++;
// 	}
// 	printf("\n");
// 	numbers[0] = 10;
// 	numbers[2] = 20;
// 	numbers[4] = 30;
// 	printf("Valeurs apres modification :\n");
// 	i = 0;
// 	while (i < n)
// 	{
// 		printf("%d ", numbers[i]);
// 		i++;
// 	}
// 	printf("\n");
// 	free(numbers);
// 	return (0);
// }