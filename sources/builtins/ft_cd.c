// #include "../../header/minishell.h"

// void	cd_absolute(t_shell *minishell)
// {
// 	char	*old;
// 	char	*new;
// 	char	path[PATH_MAX];
// 	char	path2[PATH_MAX];

// 	old = getcwd(path, PATH_MAX);
// 	if (chdir(minishell->cmds->args[1]) == -1)
// 	{
// 		perror("cd");
// 		minishell->last_exit_status = 1;
// 		return ;
// 	}
// 	new = getcwd(path2, PATH_MAX);
// 	if (new == NULL)
// 	{
// 		perror("cd");
// 		minishell->last_exit_status = 1;
// 		return ;
// 	}
// 	set_pwd(minishell, old, new);
// 	ft_update_envp(minishell->envp, "OLDPWD", old);
// 	ft_update_envp(minishell->envp, "PWD", new);
// 	minishell->last_exit_status = 0;
// }

// void	cd_relative(t_shell *minishell)
// {
// 	char	path[PATH_MAX];
// 	char	path2[PATH_MAX];
// 	char	*old;
// 	char	*new;

// 	old = getcwd(path, PATH_MAX);
// 	if (!old || chdir(minishell->cmds->args[1]) == -1)
// 	{
// 		perror("cd");
// 		minishell->last_exit_status = 1;
// 		return;
// 	}
// 	new = getcwd(path2, PATH_MAX);
// 	if (!new)
// 	{
// 		perror("cd");
// 		minishell->last_exit_status = 1;
// 		return;
// 	}
// 	set_pwd(minishell, old, new);
// 	ft_update_envp(minishell->envp, "OLDPWD", old);
// 	ft_update_envp(minishell->envp, "PWD", new);
// 	minishell->last_exit_status = 0;
// }

// void	cd_home(t_shell *minishell)
// {
// 	char	path[PATH_MAX];
// 	char	path2[PATH_MAX];
// 	char	*old;
// 	char	*new;
// 	char	*home;

// 	old = getcwd(path, PATH_MAX);
// 	home = ft_getenv(minishell->envp, "HOME");
// 	if (!home)
// 	{
// 		write(2, "cd: HOME not set\n", 17);
// 		minishell->last_exit_status = 1;
// 		return;
// 	}
// 	if (chdir(home) == -1)
// 	{
// 		perror("cd");
// 		minishell->last_exit_status = 1;
// 		return;
// 	}
// 	new = getcwd(path2, PATH_MAX);
// 	ft_update_envp(minishell->envp, "OLDPWD", old);
// 	ft_update_envp(minishell->envp, "PWD", new);
// 	minishell->last_exit_status = 0;
// }

// void	cd_tilde(t_shell *minishell, char *arg)
// {
// 	char	path[PATH_MAX];
// 	char	path2[PATH_MAX];
// 	char	*old;
// 	char	*joined;
// 	char	*home;

// 	home = ft_getenv(minishell->envp, "HOME");
// 	if (!home)
// 		return ((void)(write(2, "cd: HOME not set\n", 17),
// 			minishell->last_exit_status = 1));

// 	old = getcwd(path, PATH_MAX);
// 	joined = ft_strjoin(home, arg + 1);
// 	if (!joined || chdir(joined) == -1)
// 		return ((void)(free(joined), perror("cd"),
// 			minishell->last_exit_status = 1));
// 	ft_update_envp(minishell->envp, "OLDPWD", old);
// 	ft_update_envp(minishell->envp, "PWD", getcwd(path2, PATH_MAX));
// 	free(joined);
// 	minishell->last_exit_status = 0;
// }

// void	ft_cd(t_shell *minishell)
// {
// 	char	*arg;

// 	arg = minishell->cmds->args[1];
// 	if (!arg || arg[0] == '\0')  
// 		cd_home(minishell);
// 	else if (arg[0] == '/' )        
// 		cd_absolute(minishell);
// 	else if (arg[0] == '~')           
// 		cd_tilde(minishell, arg);
// 	else                                
// 		cd_relative(minishell);
// }
