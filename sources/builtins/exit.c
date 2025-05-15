#include "../../header/minishell.h"

char	*get_token_value(t_token *tokens, int index)
{
	int	i;

	i = 0;
	while (tokens)
	{
		if (i == index)
			return (tokens->value);
		i++;
		tokens = tokens->next;
	}
	return (NULL);
}

void	basic_exit(t_shell *minishell)
{
	struct termios	old_tio;
	char			*first;

	tcgetattr(STDIN_FILENO, &old_tio);
	first = get_token_value(minishell->tokens, 0);
	if (first && ft_strcmp(first, "exit") == 0
		&& !get_token_value(minishell->tokens, 1))
	{
		minishell->isbuiltin = 1;
		write(STDOUT_FILENO, "exit\n", 5);
		exit(minishell->last_exit_status);
	}
	tcsetattr(STDIN_FILENO, TCSANOW, &old_tio);
}

void	nb_len_error(char *str, unsigned long long nbr, int sign)
{
	int	exit_status;

	if (sign)
	{
		if (nbr > (unsigned long long)LLONG_MIN)
		{
			ft_putstr_fd("minishell: exit: ", 2);
			ft_putstr_fd(str, 2);
			ft_putstr_fd(": numeric argument required\n", 2);
			exit_status = 255;
			exit (exit_status);
		}
	}
	else if (nbr > (unsigned long long)LLONG_MAX)
	{
		ft_putstr_fd("minishell: exit: ", 2);
		ft_putstr_fd(str, 2);
		ft_putstr_fd(": numeric argument required\n", 2);
		exit_status = 255;
		exit(exit_status);
	}
}

int	ft_atol(char *str)
{
	size_t				i;
	unsigned long long	nbr;
	int					sign;

	i = 0;
	nbr = 0;
	sign = 0;
	while (str[i] && ft_isspace(str[i]))
		++i;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = 1;
		++i;
	}
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		nbr = (nbr * 10) + (str[i] - '0');
		if (nbr > LLONG_MAX)
			nb_len_error(str, nbr, sign);
		++i;
	}
	if (sign)
		return (-nbr);
	return (nbr);
}

int	ft_exit(t_shell *minishell, int is_in_fork, int print)
{
	char	*arg1;
	char	*arg2;

	if (is_in_fork != 1)
		printf("exit\n");
	arg1 = get_token_value(minishell->tokens, 1);
	arg2 = get_token_value(minishell->tokens, 2);
	if (arg1)
	{
		if (arg2)
		{
			ft_putstr_fd("minishell: exit: too many arguments\n", 2);
			minishell->last_exit_status = 1;
			print = 1;
		}
		else if (is_numeric(arg1))
			minishell->last_exit_status = (ft_atol(arg1) % 256);
		else
		{
			ft_putstr_fd("minishell: exit: ", 2);
			ft_putstr_fd(arg1, 2);
			ft_putstr_fd(": numeric argument required\n", 2);
			minishell->last_exit_status = 255;
		}
	}
	if (minishell->last_exit_status < 0)
		minishell->last_exit_status += 256;
	if (print != 1)
		exit(minishell->last_exit_status);
	return (0);
}
