


#include "../../header/minishell.h"

t_env	*create_env_node(char *env)
{
	t_env	*node;
	char	*sep;

	node = malloc(sizeof(t_env));
	if (!node)
		return (NULL);
	sep = ft_strchr(env, '=');
	if (!sep)
		return (free(node), NULL);
	node->key = ft_substr(env, 0, sep - env);
	node->value = ft_strdup(sep + 1);
	if (!node->key || !node->value)
		return (free(node->key), free(node->value), free(node), NULL);
	node->next = NULL;
	return (node);
}

void	print_env(t_env *env)
{
	while (env)
	{
		if (env->key && env->value)
		{
			printf("%s=%s\n", env->key, env->value);
		}
		env = env->next;
	}
}

t_env	*init_env_from_envp(char **envp)
{
	t_env	*head;
	t_env	*last;
	t_env	*new;
	int		i;

	i = 0;
	head = NULL;
	while (envp[i])
	{
		new = create_env_node(envp[i]);
		if (!new)
			return (NULL);
		if (!head)
			head = new;
		else
			last->next = new;
		last = new;
		i++;
	}
	return (head);
}
