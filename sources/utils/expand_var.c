#include "../../header/minishell.h"

int	check_variable(t_shell *shell)
{
	t_token	*tmp;
	char	*new_val;

	tmp = shell->tokens;
	while (tmp)
	{
		if (tmp->value && tmp->value[0] == '$')
		{
			if (ft_strcmp(tmp->value, "$?") == 0)
				new_val = ft_itoa(shell->last_exit_status);
			else
			{
				new_val = ft_getenv(shell->envp, tmp->value + 1);
				if (!new_val)
					new_val = ft_strdup("");
				else
					new_val = ft_strdup(new_val);
			}
			if (!new_val)
				return (1);
			free(tmp->value);
			tmp->value = new_val;
		}
		tmp = tmp->next;
	}
	return (0);
}
