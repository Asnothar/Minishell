


#include "../../header/minishell.h"

int	skip_whitespaces(const char *str, int i, int len)
{
	while (i < len && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
			|| str[i] == '\r' || str[i] == '\v' || str[i] == '\f'))
		i++;
	return (i);
}

int ft_strcmp(const char *s1, const char *s2)
{
	return (ft_strncmp(s1, s2, ft_strlen(s1)));
}
