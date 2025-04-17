/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaufil <abeaufil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 14:29:34 by abeaufil          #+#    #+#             */
/*   Updated: 2025/03/19 18:38:13 by abeaufil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/ultimate_libft.h"

// écrit une chaîne de caractères suivie d'un saut de ligne dans un fichier
// désigné par un descripteur de fichier fd.
void	ft_putendl_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i])
	{
		ft_putchar_fd(s[i], fd);
		i++;
	}
	ft_putchar_fd('\n', fd);
}

// int	main(void)
// {
// 	char *str = "Hello World";
// 	ft_putendl_fd(str, 1);
// 	return(0);	
// }
