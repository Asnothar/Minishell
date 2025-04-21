# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abeaufil <abeaufil@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/04 11:47:43 by abeaufil          #+#    #+#              #
#    Updated: 2025/04/21 11:52:43 by abeaufil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RED     = \033[31m
GREEN   = \033[32m
YELLOW  = \033[33m
BLUE    = \033[34m
CYAN    = \033[36m
RESET   = \033[0m

NAME	= minishell
CC		= cc
CFLAGS	= -Wall -Werror -Wextra -ggdb -gdwarf-3

SRC_PATH = sources/
OBJ_PATH = objet/

SRC		= \
		
		

SRCS	= $(addprefix $(SRC_PATH), $(SRC))
OBJ		= $(SRC:.c=.o)
OBJS	= $(addprefix $(OBJ_PATH), $(OBJ))
HEAD	= -I ./header/

LIBFT_DIR = ./sources/ultimate_libft
LIBFT_INCLUDE = -I$(LIBFT_DIR)/includes
LIBFT_LIB = $(LIBFT_DIR)/libft.a

all: $(OBJ_PATH) $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@$(CC) $(CFLAGS) -c $< -o $@ $(HEAD) $(LIBFT_INCLUDE)
	@echo "$(CYAN)🔧 Compilation de $(notdir $<)$(RESET)"

$(OBJ_PATH):
	@mkdir -p $(OBJ_PATH)
	@echo "$(YELLOW)📁 Dossier $(OBJ_PATH) créé$(RESET)"

$(NAME): $(OBJS) $(LIBFT_LIB)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT_LIB) -o $(NAME)
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
