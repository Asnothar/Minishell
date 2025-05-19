#include "../../header/minishell.h"

static char	*get_arg_value(t_shell *shell)
{
	t_token	*tok;

	tok = shell->tokens;
	if (!tok)
		return (NULL);
	tok = tok->next;
	if (!tok)
		return (NULL);
	return (tok->value);
}

static int	cd_fail(t_shell *shell, char *msg)
{
	perror(msg);
	shell->last_exit_status = 1;
	return (0);
}

static void	cd_update_env(t_shell *shell, char *old, char *new)
{
	set_pwd(shell, old, new);
	ft_update_envp(shell->envp, "OLDPWD", old);
	ft_update_envp(shell->envp, "PWD", new);
	shell->last_exit_status = 0;
}

void	cd_absolute(t_shell *shell)
{
	char	path_old[PATH_MAX];
	char	path_new[PATH_MAX];
	char	*arg;

	arg = get_arg_value(shell);
	if (!arg || !getcwd(path_old, PATH_MAX) || chdir(arg) == -1)
		return ((void)cd_fail(shell, "cd"));
	if (!getcwd(path_new, PATH_MAX))
		return ((void)cd_fail(shell, "cd"));
	cd_update_env(shell, path_old, path_new);
}

void	cd_relative(t_shell *shell)
{
	char	path_old[PATH_MAX];
	char	path_new[PATH_MAX];
	char	*arg;

	arg = get_arg_value(shell);
	if (!arg || !getcwd(path_old, PATH_MAX) || chdir(arg) == -1)
		return ((void)cd_fail(shell, "cd"));
	if (!getcwd(path_new, PATH_MAX))
		return ((void)cd_fail(shell, "cd"));
	cd_update_env(shell, path_old, path_new);
}

void	cd_home(t_shell *shell)
{
	char	path_old[PATH_MAX];
	char	path_new[PATH_MAX];
	char	*home;

	home = ft_getenv(shell->envp, "HOME");
	if (!home)
	{
		write(2, "cd: HOME not set\n", 17);
		shell->last_exit_status = 1;
		return ;
	}
	if (!getcwd(path_old, PATH_MAX) || chdir(home) == -1)
		return ((void)cd_fail(shell, "cd"));
	if (!getcwd(path_new, PATH_MAX))
		return ((void)cd_fail(shell, "cd"));
	cd_update_env(shell, path_old, path_new);
}

static char	*cd_tilde_dest(t_shell *shell, char *arg)
{
	char	*home;

	home = ft_getenv(shell->envp, "HOME");
	if (!home)
		return (NULL);
	if (arg && arg[0] == '~')
		return (ft_strjoin(home, arg + 1));
	return (ft_strdup(home));
}

void	cd_tilde(t_shell *shell)
{
	char	path_old[PATH_MAX];
	char	path_new[PATH_MAX];
	char	*arg;
	char	*dest;

	arg = get_arg_value(shell);
	dest = cd_tilde_dest(shell, arg);
	if (!dest)
	{
		write(2, "cd: HOME not set\n", 17);
		shell->last_exit_status = 1;
		return ;
	}
	if (!getcwd(path_old, PATH_MAX) || chdir(dest) == -1)
	{
		free(dest);
		return ((void)cd_fail(shell, "cd"));
	}
	free(dest);
	if (!getcwd(path_new, PATH_MAX))
		return ((void)cd_fail(shell, "cd"));
	cd_update_env(shell, path_old, path_new);
}

int	ft_cd(t_shell *shell)
{
	char	*arg;

	arg = get_arg_value(shell);
	if (!arg || arg[0] == '\0')
		cd_home(shell);
	else if (arg[0] == '/')
		cd_absolute(shell);
	else if (arg[0] == '~')
		cd_tilde(shell);
	else
		cd_relative(shell);
	return (0);
}
