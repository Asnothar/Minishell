// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   ft_pwd.c                                           :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: sjupille <sjupille@student.42.fr>          +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2025/05/01 17:47:55 by sjupille          #+#    #+#             */
// /*   Updated: 2025/05/05 14:28:04 by sjupille         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "../../header/minishell.h"

// void	cd_oldpwd(t_shell *minishell)
// {
// 	t_env	*env;
// 	char	path[PATH_MAX];
// 	char	path2[PATH_MAX];
// 	char	*oldpwd;

// 	env = minishell->envp;
// 	while (env)
// 	{
// 		if (ft_strcmp(env->key, "OLDPWD") == 0)
// 		{
// 			oldpwd = env->value;
// 			if (chdir(oldpwd) == -1)
// 			{
// 				perror("cd");
// 				minishell->last_exit_status = 1;
// 				return;
// 			}
// 			printf("%s\n", oldpwd);
// 			ft_pwd(minishell, getcwd(path, PATH_MAX), getcwd(path2, PATH_MAX));
// 			ft_update_envp(minishell->envp, "OLDPWD", path);
// 			ft_update_envp(minishell->envp, "PWD", path2);
// 			minishell->last_exit_status = 0;
// 			return;
// 		}
// 		env = env->next;
// 	}
// 	ft_putstr_fd("cd: OLDPWD not set\n", 2);
// 	minishell->last_exit_status = 1;
// }

// int	pwd(void)
// {
// 	char	path[PATH_MAX];

// 	if (!getcwd(path, PATH_MAX))
// 	{
// 		ft_putstr_fd("getcwd ERROR!\n", 2);
// 		return (1);
// 	}
// 	ft_putstr_fd(path, 1);
// 	write(1, "\n", 1);
// 	return (0);
// }
