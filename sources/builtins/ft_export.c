
// // fonction export de base sans options: affichage pur de la liste
// // trouver la longueur de la liste des variables d'environnement, les classer par ordre alphabetique et les afficher

// int	env_len(t_env *envp)
// {
// 	int	i;


// 	i = 0;
// 	while (envp)
// 	{
// 		i++;
// 		envp = envp->next;
// 	}
// 	return (i);
// }


// t_env	*find_min(t_env *envp, t_env *prev_min)
// {
// 	t_env	*min;


// 	min = NULL;
// 	while (envp)
// 	{
// 		if ((!prev_min || ft_strcmp(envp->key, prev_min->key) > 0)
// 			&& (!min || ft_strcmp(envp->key, min->key) < 0))
// 			min = envp;
// 		envp = envp->next;
// 	}
// 	return (min);
// }

// void	ft_print_export(t_env *envp)
// {
// 	int		len;
// 	t_env	*prev_min;
// 	int		i;
// 	t_env	*current_min;

// 	prev_min = NULL;
// 	len = env_len(env);
// 	i = 0;
// 	while (i < len)
// 	{
// 		current_min = find_min(envp, prev_min);
// 		if (current_min == NULL)
// 			break ;
// 		ft_printf("declare -x %s", current_min->key);
// 		if (current_min->value)
// 			ft_printf("=\"%s\"", current_min->value);
// 		ft_printf("\n");
// 		prev_min = current_min;
// 		i++;
// 	}
// }
