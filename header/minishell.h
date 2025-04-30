/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaufil <abeaufil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 17:42:19 by abeaufil          #+#    #+#             */
/*   Updated: 2025/04/30 11:45:56 by abeaufil         ###   ########.fr       */
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

//	parsing
//		parsing1.c
int		check_quotes(char *line);
int		check_pipe(char *line);
int		check_redirection(char *line);
int		check_special_characters(char *line);
int		check_syntax(char *line);

//	utils
//		utils1.c
int		skip_whitespaces(const char *str, int i, int len);
void	print_tokens(char **tokens);
//		tokens.c
char	*handle_quotes(const char *line, size_t *i, size_t len);
char	*handle_special_characters(const char *line, size_t *i);
char	**initialize_tokens(size_t len);
char	*process_token(const char *line, size_t *i, size_t len);
char	**tokenize_input(const char *line);

#endif
