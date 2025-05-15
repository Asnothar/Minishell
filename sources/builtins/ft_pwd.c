#include "../../header/minishell.h"

void	set_pwd(t_shell *minishell, char *old, char *new)
{
	t_env	*env;

	env = minishell->envp;
	while (env)
	{
		if (ft_strcmp(env->key, "PWD") == 0)
		{
			free(env->value);
			env->value = ft_strdup(new);
		}
		else if (ft_strcmp(env->key, "OLDPWD") == 0)
		{
			free(env->value);
			env->value = ft_strdup(old);
		}
		env = env->next;
	}
}

int	ft_pwd(void)
{
	char	path[PATH_MAX];

	if (!getcwd(path, PATH_MAX))
	{
		ft_putstr_fd("getcwd ERROR!\n", 2);
		return (1);
	}
	ft_putstr_fd(path, 1);
	write(1, "\n", 1);
	return (0);
}
