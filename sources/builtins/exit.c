


#include "../../header/minishell.h"

void	basic_exit(t_shell *minishell)
{
	struct termios	old_tio;

	tcgetattr(STDIN_FILENO, &old_tio);
	if (ft_strcmp(minishell->cmds->args[0], "exit") == 0 && !(minishell->cmds->args[1]))
	{
		minishell->isbuiltin = 1;
		write(STDOUT_FILENO, "exit\n", 5);
		exit(minishell->last_exit_status);
	}
	tcsetattr(STDIN_FILENO, TCSANOW, &old_tio);
}

static int	is_numeric(const char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

static void	nb_len_error(char *str, unsigned long long nbr, int sign)
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

void	ft_exit(t_shell *minishell, int is_in_fork, int print)
{
	if (is_in_fork != 1)
		printf("exit\n");
	if (minishell->cmds->args[1])
	{
		if (minishell->cmds->args[2])
		{
			ft_putstr_fd("minishell: exit: too many arguments\n", 2);
			minishell->last_exit_status = 1;
			print = 1;
		}
		else if (is_numeric(minishell->cmds->args[1]))
			minishell->last_exit_status = (ft_atol(minishell->cmds->args[1]) % 256);
		else
		{
			ft_putstr_fd("minishell: exit: ", 2);
			ft_putstr_fd(minishell->cmds->args[1], 2);
			ft_putstr_fd(": numeric argument required\n", 2);
			minishell->last_exit_status = 255;
		}
	}
	if (minishell->last_exit_status < 0)
		minishell->last_exit_status += 256;
	if (print != 1)
		exit(minishell->last_exit_status);
}
