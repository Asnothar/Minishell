



#ifndef MINISHELL_H
# define MINISHELL_H

# define RED "\033[31m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define BLUE "\033[34m"
# define MAGENTA "\033[35m"
# define CYAN "\033[36m"
# define RESET "\033[0m"
# define PATH_MAX 1024
#define LLONG_MAX 9223372036854775807LL
#define LLONG_MIN (-9223372036854775807LL - 1)


# include "../sources/ultimate_libft/header/ultimate_libft.h"

# include <readline/readline.h>
# include <readline/history.h>
# include <sys/wait.h>
# include <signal.h>
# include <sys/stat.h>
# include <dirent.h>
# include <string.h>
# include <termios.h>
# include <sys/ioctl.h>
# include <termcap.h>
# include <stdbool.h>
# include <limits.h>



typedef struct s_cmd
{
	char			**args;	// Arguments de la commande (argv)
	char			*infile;	// Fichier en entrée (<)
	char			*outfile;	// Fichier en sortie (>)
	char			*heredoc_delim;	// Délimiteur pour le here_doc (<<)
	int				pipe_fd[2];	// Pipe vers la commande suivante (si besoin)
	struct s_cmd	*next;	// Commande suivante (pour pipe ou multiples commandes)
}	t_cmd;

typedef struct s_env
{
	char			*key;	// Clé de l'environnement
	char			*value;	// Valeur de l'environnement
	struct s_env	*next;	// Prochain élément de la liste chaînée
}	t_env;

typedef struct s_shell
{
	char			**env;	// Copie de l'environnement
	t_env			*envp;  // Copie de l environnement en liste chainee
	char			*input;	// Ligne de commande entrée par l'utilisateur
	struct s_cmd	*cmds;	// Liste chaînée de commandes parsées
	char			*infile;
	char			*outfile;
	int				isbuiltin;
	int				last_exit_status;	// Code de retour de la dernière commande exécutée
}	t_shell;

typedef struct s_token
{
	char			*value;
	struct s_token	*next;
}	t_token;

typedef enum e_token_type
{
	WORD,
	PIPE,
	REDIR_IN,
	REDIR_OUT,
	HERE_DOC,
	APPEND,
}	t_token_type;

//	parsing
//		parsing1.c
int		check_quotes(char *line);
int		check_pipe(char *line);
int		check_redirection(char *line);
int		check_special_characters(char *line);
int		check_syntax(char *line);
//              parsing2.c
void	err_message(char *message1, char *message2, char *message3);

//	utils
//		init.c
t_cmd	*init_cmd(void);
t_shell	*init_shell(void);
t_env	*init_env(void);
void	free_cmd(t_cmd *cmd);
void	start_init(void);
//		signal.c
void	handle_sigint(int sig);
void	handle_sigquit(int sig);
void	setup_signals(void);
//		tokens.c
char	*handle_quotes(const char *line, size_t *i, size_t len);
char	*handle_special_characters(const char *line, size_t *i);
char	*process_token(const char *line, size_t *i, size_t len);
t_token	*create_token_node(char *value);
void	add_token_back(t_token **head, t_token *new);
t_token	*tokenize_input(const char *line);
//		utils_1.c
int		skip_whitespaces(const char *str, int i, int len);
void	print_tokens(char **tokens);
void	free_split(char **split);
void	free_token_list(t_token *head);
int		ft_strcase(char *str, char *with_whom);

//  builtins
//      ft_cd.c
void	cd_absolute(t_shell *minishell);
void	cd_relative(t_shell *minishell);
void	cd_home(t_shell *minishell);
void	cd_tilde(t_shell *minishell, char *arg);
void	ft_cd(t_shell *minishell);
//      ft_echo.c
void	ft_echo(t_shell *minishell);
//      ft_env.c
char	*ft_getenv(t_env *envp, const char *name);
void	ft_update_envp(t_env *envp, const char *name, const char *value);
void	ft_env(t_shell *minishell);
//      ft_pwd.c
void	cd_oldpwd(t_shell *minishell);
int		pwd(void);
//      ft_exit.c
void	basic_exit(t_shell *minishell);
int		ft_atol(char *str);
void	ft_exit(t_shell *minishell, int is_in_fork, int print);
//      ft_export.c
void	ft_print_export(t_env *envp);
//      ft_export2.c
void	export(t_shell *minishell);
//      isbuiltins.c
int		is_builtin(t_shell *minishell, char **command);
//      unset.c
void	unset(t_shell *minishell, char **cmd);

#endif
