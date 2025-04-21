/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaufil <abeaufil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 08:43:22 by abeaufil          #+#    #+#             */
/*   Updated: 2025/03/17 11:12:50 by abeaufil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/ultimate_libft.h"

static int	check_type(const char *input, va_list *args)
{
	int	i;

	i = 0;
	if (*input == 'c')
		i += print_char(va_arg(*args, int));
	else if (*input == 's')
		i += print_string(va_arg(*args, char *));
	else if (*input == 'p')
		i += print_pointer((unsigned long)va_arg(*args, void *));
	else if (*input == 'd' || *input == 'i')
		i += print_int(va_arg(*args, int));
	else if (*input == 'u')
		i += print_unsigned(va_arg(*args, unsigned int));
	else if (*input == 'x')
		i += print_hex(va_arg(*args, unsigned int), 87);
	else if (*input == 'X')
		i += print_hex(va_arg(*args, unsigned int), 55);
	return (i);
}

int	ft_printf(const char *input, ...)
{
	va_list			args;
	unsigned int	i;

	i = 0;
	va_start(args, input);
	while (*input != '\0')
	{
		if (*input == '%')
		{
			input++;
			if (ft_strchr("cspdiuxX", *input))
				i += check_type(input, &args);
			else if (*input == '%')
				i += print_char('%');
		}
		else
			i += print_char(*input);
		input++;
	}
	va_end(args);
	return (i);
}

// int main()
// {
// 	int	test = 1;

// 	printf("%d | ", printf("Test Numero : %d %u \n" , test, 42 ));
// 	printf("%d | ", ft_printf("Test Numero : %d %u \n" , test, 42));
// 	return (0);
// }