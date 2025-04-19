# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sjupille <sjupille@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/14 16:49:42 by sjupille          #+#    #+#              #
#    Updated: 2025/02/20 09:14:24 by sjupille         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
SRCS_DIR	= SRCS/
GNL_SRCS_DIR	= GNL_SRCS/
SRCS		= $(SRCS_DIR)ft_errors.c \
			  $(SRCS_DIR)commands.c \
			  $(SRCS_DIR)libft_utils.c \
			  $(SRCS_DIR)ft_split.c \
			  $(SRCS_DIR)init.c\
			  $(SRCS_DIR)process.c\
			  $(SRCS_DIR)pipex.c

GNL_SRCS	= $(GNL_SRCS_DIR)get_next_line.c \
			  $(GNL_SRCS_DIR)get_next_line_utils.c

INCLUDES = -I includes

OBJ_DIR		= obj
OBJS		= $(addprefix $(OBJ_DIR)/, $(notdir $(SRCS:.c=.o)))
GNL_OBJS	= $(addprefix $(OBJ_DIR)/, $(notdir $(GNL_SRCS:.c=.o)))

CC			= cc
CFLAGS		= -Wall -Wextra -Werror -g
RM			= rm -f

# Couleurs
GREEN = \033[1;32m
BLUE = \033[0;34m
YELLOW = \033[1;33m
RED = \033[0;31m
END = \033[0m

$(OBJ_DIR)/%.o : $(SRCS_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR)/%.o : $(GNL_SRCS_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	
all : $(NAME)

$(NAME) : $(OBJS) $(GNL_OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(GNL_OBJS) -o $(NAME)
	@echo "$(GREEN)$(NAME) created !$(END)"

clean :
	@$(RM) $(OBJS) $(GNL_OBJS)
	@echo "$(YELLOW)Object files deleted !$(END)"

fclean : clean
	@$(RM) $(NAME)
	@echo "$(RED)All deleted !$(END)"

re : fclean all

.PHONY : all clean fclean re