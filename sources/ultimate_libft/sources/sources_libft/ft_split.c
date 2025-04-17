/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaufil <abeaufil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 11:46:41 by abeaufil          #+#    #+#             */
/*   Updated: 2025/03/19 17:38:07 by abeaufil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/ultimate_libft.h"

static int	count_word(const char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0' && s[i] != c)
		{
			while (s[i] != '\0' && s[i] != c)
				i++;
			count++;
		}
	}
	return (count);
}

static char	*copy_str(const char *s, int start, int end)
{
	return (ft_substr(s, start, (end - start)));
}

static void	free_tab(char **tab, int y)
{
	while (y >= 0)
	{
		free(tab[y]);
		y--;
	}
	free(tab);
}

static int	ft_copy_str_tab(char **tab, const char *s, char c, int start)
{
	int	i;
	int	y;

	i = 0;
	y = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		start = i;
		while (s[i] != '\0' && s[i] != c)
			i++;
		if (i > start)
		{
			tab[y] = copy_str(s, start, i);
			if (!tab[y])
				return (free_tab(tab, y - 1), 0);
			y++;
		}
	}
	tab[y] = NULL;
	return (1);
}

// Divise une chaîne en sous-chaînes en fonction d'un délimiteur et
// retourne un tableau alloué dynamiquement.
char	**ft_split(const char *s, char c)
{
	char	**tab;

	if (!s)
		return (NULL);
	tab = malloc((count_word(s, c) + 1) * sizeof(char *));
	if (!tab)
		return (NULL);
	if (!ft_copy_str_tab(tab, s, c, 0))
		return (NULL);
	return (tab);
}

// int main(int argc, char **argv)
// {
// 	(void)argc;
// 	char **tab = ft_split(argv[1], argv[2][0]);
// 	int i = 0;
// 	while (tab[i] != NULL)
// 	{
// 		printf("%s\n", tab[i]);
// 		i++;
// 	}
// }
