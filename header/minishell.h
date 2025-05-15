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
# define LLONG_MAX 9223372036854775807LL
# define LLONG_MIN (-9223372036854775807LL - 1)

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

typedef struct s_env
{
	char			*key;
	char			*value;
	struct s_env	*next;
}	t_env;

typedef struct s_token
{
	char			*value;
	struct s_token	*next;
}	t_token;

typedef struct s_shell
{
	char			**env;
	t_env			*envp;
	char			*input;
	t_token			*tokens;
	char			*infile;
	char			*outfile;
	char			*heredoc_delim;
	int				isbuiltin;
	int				last_exit_status;
}	t_shell;

typedef enum e_token_type
{
	WORD,
	PIPE,
	REDIR_IN,
	REDIR_OUT,
	HERE_DOC,
	APPEND,
}	t_token_type;

//		parsing
//				parsing1.c
int				parse(t_shell *shell);
int				command_type(t_shell *shell);
//				parsing2.c
void			err_message(char *message1, char *message2, char *message3);

//		utils
//				copy_env.c
t_env			*create_env_node(char *env);
void			print_env(t_env *env);
t_env			*init_env_from_envp(char **envp);
//				free_1.c
void			free_split(char **split);
void			free_token_list(t_token *head);
void			free_shell(t_shell *shell);
void			free_env_list(t_env *head);
//				init.c
t_shell			*init_shell(char **envp);
t_shell			*start_init(char **envp);
//				print_debug.c
t_token_type	get_token_type(char *token);
char			*get_token_type_str(t_token_type type);
void			print_debug_info(char *line, t_token *tokens);
//				signal.c
void			handle_sigint(int sig);
void			handle_sigquit(int sig);
void			setup_signals(void);
//				tokens.c
char			*handle_quotes(const char *line, size_t *i, size_t len);
char			*handle_special_characters(const char *line, size_t *i);
char			*process_token(const char *line, size_t *i, size_t len);
t_token			*create_token_node(char *value);
void			add_token_back(t_token **head, t_token *new);
t_token			*tokenize_input(const char *line);
//				utils_1.c
int				skip_whitespaces(const char *str, int i, int len);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_isspace(int c);
int				ft_is_numeric(const char *str);
//				utils_2.c

//		builtins
//				ft_cd.c
void			cd_absolute(t_shell *minishell);
void			cd_relative(t_shell *minishell);
void			cd_home(t_shell *minishell);
void			cd_tilde(t_shell *minishell, char *arg);
void			ft_cd(t_shell *minishell);
//				ft_echo.c
int				ft_echo(t_shell *minishell);
//				ft_env.c
char			*ft_getenv(t_env *envp, const char *name);
void			ft_update_envp(t_env *envp, const char *name, const char *value);
int				ft_env(t_shell *minishell);
//				ft_pwd.c
void			set_pwd(t_shell *minishell, char *old, char *new);
int				ft_pwd(void);
//				ft_exit.c
char			*get_token_value(t_token *tokens, int index);
void			basic_exit(t_shell *minishell);
void			nb_len_error(char *str, unsigned long long nbr, int sign);
int				ft_atol(char *str);
int				ft_exit(t_shell *minishell, int is_in_fork, int print);
//				ft_export.c
int				env_len(t_env *envp);
t_env			*find_min(t_env *envp, t_env *prev_min);
void			ft_print_export(t_env *envp);
//				ft_export2.c
void			export(t_shell *minishell);
int				valid_export_arg(char *str);
void			export_change(t_env *envp, char *str, int equal_index);
t_env			*get_newnode(char *key, t_env *envp);
//				isbuiltins.c
int				ft_strcase(char *str, char *with_whom);
int				is_builtin(t_shell *minishell, char **command);
int				is_builtin2(t_shell *minishell);
//				unset.c
void			unset(t_shell *minishell, char **cmd);
void			unset1(t_shell *minishell, t_env *tmp, t_env *prev, int i);

//		execution
//				pipex.c
int				pipe_count(t_shell *minishell);
void			pipex(t_shell *minishell, int **fd, int pipe_index, int pipe_count);
void			close_fd(int **fd, int count);
void			waiting_childs(t_shell *minishell, int nb_cmds);
//				heredocs.c
void			here_doc1(int write_end, char *limiter);
int				here_doc(t_shell *shell);
//				redirs.c
int				open_infile(char *file);
int				open_outfile(char *file, t_token_type type);
void			in_redir(t_shell *shell);
void			out_redir(t_shell *minishell, t_token_type type);
void			redirs(t_shell *minishell, t_token_type out_type);

#endif
