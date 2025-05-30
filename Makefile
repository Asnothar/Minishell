



RED     = \033[31m
GREEN   = \033[32m
YELLOW  = \033[33m
BLUE    = \033[34m
CYAN    = \033[36m
RESET   = \033[0m

NAME	= minishell
CC		= cc
CFLAGS	= -Wall -Werror -Wextra -ggdb -gdwarf-3
LDFLAGS = -lreadline

SRC_PATH = sources/
OBJ_PATH = objet/

SRC		=	\
			utils/copy_env.c \
			utils/expand_var.c \
			utils/free_1.c \
			utils/init.c \
			utils/print_debug.c \
			utils/signal.c \
			utils/tokens.c \
			utils/utils_1.c \
			utils/utils_2.c \
			\
			builtins/exit.c \
			builtins/ft_cd.c \
			builtins/ft_echo.c \
			builtins/ft_env.c \
			builtins/ft_export.c \
			builtins/ft_export2.c \
			builtins/ft_pwd.c \
			builtins/isbuiltins.c \
			builtins/unset.c \
			\
			parsing/parsing_1.c \
			parsing/parsing_2.c \
			\
			execution/heredocs.c \
			execution/pipex.c \
			execution/redirs.c \
			\
			main.c \

SRCS	= $(addprefix $(SRC_PATH), $(SRC))
OBJ		= $(SRC:.c=.o)
OBJS	= $(addprefix $(OBJ_PATH), $(OBJ))
HEAD	= -I ./header/

LIBFT_DIR = ./sources/ultimate_libft
LIBFT_INCLUDE = -I$(LIBFT_DIR)/includes
LIBFT_LIB = $(LIBFT_DIR)/libft.a

all: $(OBJ_PATH) $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(dir $@)  # Ensure the directory exists
	@$(CC) $(CFLAGS) -c $< -o $@ $(HEAD) $(LIBFT_INCLUDE)
	@echo "$(CYAN)🔧 Compilation de $(notdir $<)$(RESET)"

$(OBJ_PATH):
	@mkdir -p $(OBJ_PATH)
	@echo "$(YELLOW)📁 Dossier $(OBJ_PATH) créé$(RESET)"

$(NAME): $(OBJS) $(LIBFT_LIB)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT_LIB) -o $(NAME) $(LDFLAGS)
	@echo "$(GREEN)✅ $(NAME) créé avec succès !$(RESET)"

$(LIBFT_LIB):
	@$(MAKE) -C $(LIBFT_DIR) > /dev/null 2>&1

clean:
	@rm -rf $(OBJ_PATH)
	@echo "$(YELLOW)🧹 Suppression des objets$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) fclean -C $(LIBFT_DIR) > /dev/null 2>&1
	@echo "$(RED)🗑️  Suppression complète$(RESET)"

re: fclean all

.PHONY: all clean fclean re

