#include "../../header/minishell.h"

char	*ft_getenv(t_env *envp, const char *name)
{
	while (envp)
	{
		if (ft_strcmp(envp->key, name) == 0)
			return (envp->value);
		envp = envp->next;
	}
	return (NULL);
}

void	ft_update_envp(t_env *envp, const char *name, const char *value)
{
	t_env	*tmp;
	t_env	*new;

	tmp = envp;
	while (tmp)
	{
		if (strcmp(tmp->key, name) == 0)
		{
			free(tmp->value);
			tmp->value = strdup(value);
			return ;
		}
		if (!tmp->next)
			break ;
		tmp = tmp->next;
	}
	new = malloc(sizeof(t_env));
	if (!new)
		return ;
	new->key = strdup(name);
	new->value = strdup(value);
	new->next = NULL;
	tmp->next = new;
}

int	ft_env(t_shell *minishell)
{
	t_token	*token;
	t_env	*env;

	token = minishell->tokens;
	if (token && token->next)
	{
		err_message("minishell: ", token->next->value,
			": No such file or directory\n");
		minishell->last_exit_status = 1;
		return (1);
	}
	env = minishell->envp;
	while (env)
	{
		if (env->value)
		{
			ft_putstr_fd(env->key, 1);
			write(1, "=", 1);
			ft_putstr_fd(env->value, 1);
			write(1, "\n", 1);
		}
		env = env->next;
	}
	minishell->last_exit_status = 0;
	return (0);
}
