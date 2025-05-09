


// #include "../../header/minishell.h"

// void	unset1(t_shell *minishell, t_env *tmp, t_env *prev, int i)
// {
// 	while (tmp)
// 	{		
// 		if (ft_strcmp(tmp->key, minishell->cmds->args[i]) == 0)
// 		{
// 			if (!prev)
// 			{
// 				tmp = tmp->next;
// 				free(minishell->envp->key);
// 				free(minishell->envp->value);
// 				free(minishell->envp);
// 				minishell->envp = tmp;
// 				return ;
// 			}
// 			prev->next = tmp->next;
// 			free(tmp->key);
// 			free(tmp->value);
// 			free(tmp);
// 			break ;
// 		}
// 		prev = tmp;
// 		tmp = tmp -> next;
// 	}
// }

// void	unset(t_shell *minishell, char **cmd)
// {
// 	t_env	*prev;
// 	t_env	*tmp;
// 	int		i;

// 	i = 0;
// 	while (cmd[i])
// 	{
// 		if (!valid_export_arg(cmd[i]))
// 		{
// 			err_message("minishell: unset: `", cmd[i],
// 				"': not a valid identifier\n");
// 			minishell->last_exit_status = 1;
// 			return ;				
// 		}
// 		prev = NULL;
// 		tmp = minishell->envp;
// 		unset1(minishell, tmp, prev, i);
// 		i++;
// 	}
// }
