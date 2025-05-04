/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaufil <abeaufil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 17:42:19 by abeaufil          #+#    #+#             */
/*   Updated: 2025/05/01 11:45:15 by abeaufil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

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

typedef struct s_cmd
{
	char			**args;	// Arguments de la commande (argv)
	char			*infile;	// Fichier en entrée (<)
	char			*outfile;	// Fichier en sortie (>)
	char			*heredoc_delim;	// Délimiteur pour le here_doc (<<)
	int				pipe_fd[2];	// Pipe vers la commande suivante (si besoin)
	struct s_cmd	*next;	// Commande suivante (pour pipe ou multiples commandes)
}	t_cmd;

typedef struct s_shell
{
	char			**envp;	// Copie de l'environnement
	t_env			*envp;
	char			*input;	// Ligne de commande entrée par l'utilisateur
	struct s_cmd	*cmds;	// Liste chaînée de commandes parsées
	int				last_exit_status;	// Code de retour de la dernière commande exécutée
}	t_shell;

typedef struct s_env
{
	char			*key;	// Clé de l'environnement
	char			*value;	// Valeur de l'environnement
	struct s_env	*next;	// Prochain élément de la liste chaînée
}	t_env;

typedef enum e_token_type
{
	WORD,
	PIPE,
	REDIR_IN,
	REDIR_OUT,
	HERE_DOC,
	APPEND
}	t_token_type;

//	parsing
//		parsing1.c
int		check_quotes(char *line);
int		check_pipe(char *line);
int		check_redirection(char *line);
int		check_special_characters(char *line);
int		check_syntax(char *line);

//	utils
//		init.c
t_cmd	*init_cmd(void);
t_shell	*init_shell(void);
t_env	*init_env(void);
void	free_cmd(t_cmd *cmd);
void	start_init(void);
//		tokens.c
char	*handle_quotes(const char *line, size_t *i, size_t len);
char	*handle_special_characters(const char *line, size_t *i);
char	**initialize_tokens(size_t len);
char	*process_token(const char *line, size_t *i, size_t len);
char	**tokenize_input(const char *line);
//		signal.c
void	handle_sigint(int sig);
void	handle_sigquit(int sig);
void	setup_signals(void);
//		utils1.c
int		skip_whitespaces(const char *str, int i, int len);
void	print_tokens(char **tokens);

#endif
