


#include "../../header/minishell.h"

static t_env	*get_newnode(char *key, t_env *envp)
{
	t_env	*tmp;

	tmp = malloc(sizeof(t_env));
	if (!tmp)
		return (NULL);
	tmp->key = key;
	tmp->value = NULL;
	tmp->next = NULL;
	while (envp->next)
		envp = envp->next;
	envp->next = tmp;
	return (tmp);
}

static void	export_change(t_env *envp, char *str, int equal_index)
{
	char	*key;
	t_env	*tmp;

	while (str[equal_index] && str[equal_index] != '=')
		equal_index++;
	key = ft_substr(str, 0, equal_index);
	tmp = envp;
	while (tmp && ft_strcmp(tmp->key, key))
		tmp = tmp -> next;
	if (!tmp)
		tmp = get_newnode(key, envp);
	else
	{
		free(key);
		if (!ft_strchr(str, '='))
			return ;
	}
	if (tmp->value)
		free(tmp->value);
	if (ft_strchr(str, '='))
		tmp->value = ft_substr(str, equal_index + 1,
				ft_strlen(str + equal_index - 1));
	else
		tmp->value = NULL;
}

static int	valid_export_arg(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[i] == '=')
			break ;
		if (!((str[i] >= 'A' && str[i] <= 'Z')
				|| (str[i] >= 'a' && str[i] <= 'z')
				|| (str[i] >= '0' && str[i] <= '9' && i > 0) || str[i] == '_'))
			return (0);
		i++;
	}
	return (1);
}

void	export(t_shell *minishell)
{
	int	i;

	i = 1;
	while (minishell->cmds->args[i])
	{
		if ((minishell->cmds->args[i][0] && (minishell->cmds->args[i][0] == '='
			|| ft_strstr(minishell->cmds->args[i], " =")))
			|| !valid_export_arg(minishell->cmds->args[i]))
		{
			err_message("minishell: export: `", minishell->cmds->args[i],
				"': not a valid identifier\n");
			minishell->last_exit_status = 1;
		}
		else
		{
			export_change(minishell->envp, minishell->cmds->args[i], 0);
			minishell->last_exit_status = 0;	
		}
		i++;
	}
}
