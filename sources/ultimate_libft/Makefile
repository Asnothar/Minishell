# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abeaufil <abeaufil@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/23 14:10:56 by abeaufil          #+#    #+#              #
#    Updated: 2025/03/17 14:32:57 by abeaufil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RED     = \033[31m
GREEN   = \033[32m
YELLOW  = \033[33m
BLUE    = \033[34m
CYAN    = \033[36m
RESET   = \033[0m

NAME	= libft.a
CC		= cc
CFLAGS	= -Wall -Werror -Wextra -ggdb -gdwarf-3
AR		= ar rcs
RM		= rm -f

LIBFT_PATH   = sources/sources_libft/
PRINTF_PATH  = sources/sources_printf/
GNL_PATH     = sources/sources_GNL/
OBJ_PATH     = objet/

LIBFT_SRC = \
	ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
	ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
	ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c \
	ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c \
	ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c \
	ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putnbr_fd.c \
	ft_putendl_fd.c ft_split.c ft_itoa.c

BONUS = \
	ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c \
	ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c \
	ft_lstiter_bonus.c ft_lstclear_bonus.c ft_lstmap_bonus.c

PRINTF_SRC = \
	ft_printf.c \
	print_char.c print_hex.c print_pointer.c print_string.c \
	print_int.c print_unsigned.c

GNL_SRC = get_next_line.c gnl_utils.c \

SRCS        = $(addprefix $(LIBFT_PATH), $(LIBFT_SRC))
BONUS_SRCS  = $(addprefix $(LIBFT_PATH), $(BONUS))
PRINTF_SRCS = $(addprefix $(PRINTF_PATH), $(PRINTF_SRC))
GNL_SRCS    = $(addprefix $(GNL_PATH), $(GNL_SRC))

OBJS        = $(patsubst %.c, $(OBJ_PATH)%.o, $(notdir $(SRCS)))
BONUS_OBJS  = $(patsubst %.c, $(OBJ_PATH)%.o, $(notdir $(BONUS_SRCS)))
PRINTF_OBJS = $(patsubst %.c, $(OBJ_PATH)%.o, $(notdir $(PRINTF_SRCS)))
GNL_OBJS    = $(patsubst %.c, $(OBJ_PATH)%.o, $(notdir $(GNL_SRCS)))

HEAD = -I ./header/

all: $(OBJ_PATH) $(NAME)

$(OBJ_PATH):
	@mkdir -p $(OBJ_PATH)
	@echo "$(YELLOW)📁 Dossier $(OBJ_PATH) créé$(RESET)"

$(OBJ_PATH)%.o: $(LIBFT_PATH)%.c | $(OBJ_PATH)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(CYAN)🔧 Compilation de $(notdir $<)$(RESET)"

$(OBJ_PATH)%.o: $(PRINTF_PATH)%.c | $(OBJ_PATH)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(CYAN)🔧 Compilation de $(notdir $<)$(RESET)"

$(OBJ_PATH)%.o: $(GNL_PATH)%.c | $(OBJ_PATH)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(CYAN)🔧 Compilation de $(notdir $<)$(RESET)"

$(NAME): $(OBJS) $(PRINTF_OBJS) $(GNL_OBJS)
	@$(AR) $(NAME) $(OBJS) $(PRINTF_OBJS) $(GNL_OBJS)
	@echo "$(GREEN)✅ $(NAME) créé avec succès !$(RESET)"

bonus: $(BONUS_OBJS)
	@$(AR) $(NAME) $(BONUS_OBJS)
	@echo "$(GREEN)✅ libft_bonus créé avec succès !$(RESET)"

clean:
	@$(RM) $(OBJS) $(BONUS_OBJS) $(PRINTF_OBJS) $(GNL_OBJS)
	@echo "$(YELLOW)🧹 Suppression des objets$(RESET)"

fclean: clean
	@$(RM) $(NAME)
	@rm -rf $(OBJ_PATH)
	@echo "$(RED)🗑️  Suppression complète$(RESET)"

re: fclean all
