/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaufil <abeaufil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 10:36:27 by abeaufil          #+#    #+#             */
/*   Updated: 2025/02/20 10:34:07 by abeaufil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/ultimate_libft.h"

static char	*create_string(unsigned int value, int *strlen)
{
	int				i;
	unsigned int	temp;
	char			*str;

	i = 0;
	temp = value;
	while (temp != 0)
	{
		temp = temp / 16;
		i++;
	}
	str = ft_calloc(i + 1, sizeof(char));
	*strlen = i - 1;
	return (str);
}

int	print_hex(unsigned int value, int asc)
{
	unsigned int	tempval;
	char			*printout;
	int				i;
	int				*iptr;

	iptr = &i;
	tempval = value;
	printout = create_string(value, iptr);
	if (!printout)
		return (0);
	while (tempval != 0)
	{
		if ((tempval % 16) < 10)
			printout[i] = (tempval % 16) + 48;
		else
			printout[i] = (tempval % 16) + asc;
		tempval = tempval / 16;
		i--;
	}
	ft_putstr_fd(printout, 1);
	i = ft_strlen(printout);
	free(printout);
	if (value == 0)
		i += print_char('0');
	return (i);
}
