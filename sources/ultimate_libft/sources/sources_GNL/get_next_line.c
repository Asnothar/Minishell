/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaufil <abeaufil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 13:46:19 by abeaufil          #+#    #+#             */
/*   Updated: 2025/03/17 14:29:18 by abeaufil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/ultimate_libft.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*str;
	int			read_byte;

	str = NULL;
	read_byte = 1;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str = process_buffer(buffer, str);
	while (read_byte > 0 && is_new_line(buffer) == 0)
	{
		read_byte = read(fd, buffer, BUFFER_SIZE);
		if (read_byte < 0)
			return (free(str), NULL);
		if (read_byte == 0)
		{
			if (str != NULL && str[0] != '\0')
				return (str);
			return (free(str), NULL);
		}
		buffer[read_byte] = '\0';
		str = ft_strjoin_gnl(str, buffer);
	}
	return (str);
}

// int main(int argc, char **argv)
// {
// 	if (argc != 2)
// 	{
// 		printf("Usage: %s <file_name>\n", argv[0]);
// 		return (1);
// 	}
// 	int fd = open(argv[1], O_RDONLY);
// 	if (fd < 0)
// 	{
// 		perror("Error opening file");
// 		return (1);
// 	}
// 	int	count = 0; 
// 	if (count < 5)
// 	{
// 		printf("%s", get_next_line(fd));
// 		count++;
// 	}
// 	if (close(fd) < 0)
// 	{
// 		perror("Error closing file");
// 		return (1);
// 	}
// 	return (0);
// }
