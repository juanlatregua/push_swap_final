# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jsilva-m <jsilva-m@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/09 19:47:55 by jsilva-m          #+#    #+#              #
#    Updated: 2024/09/12 20:19:21 by jsilva-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = gcc
CFLAGS = -Wall -Werror -Wextra -Iincludes -Ilibft/includes
LIBFT = libft/libft.a
RM = rm -rf

SRC_MAIN = src/push_swap/main.c
SRCS_AUX = \
	src/push_swap/operations/push.c\
	src/push_swap/operations/reverse_rotate.c\
	src/push_swap/operations/rotate.c\
	src/push_swap/operations/swap.c\
	src/push_swap/do_move.c\
	src/push_swap/input_check_utils.c\
	src/push_swap/input_check.c\
	src/push_swap/position.c\
	src/push_swap/sort_utils.c\
	src/push_swap/sort.c\
	src/push_swap/stack_functions.c\
	src/push_swap/utils.c

OBJ_MAIN = $(SRC_MAIN:src/%.c=obj/%.o)
OBJS_AUX = $(SRCS_AUX:src/%.c=obj/%.o)

######################### Directories ################################
OBJ_DIR = obj

######################### Compilation Rules ##########################
all: $(NAME)

clean:
	@$(RM) $(OBJ_DIR)
	@$(RM) $(NAME)
	@echo "[Cleaned objects and executable]"

fclean: clean
	@make -sC libft fclean
	@echo "[Full clean done]"

re: fclean all

$(OBJ_DIR)/%.o: src/%.c
	@mkdir -p $(OBJ_DIR)/push_swap/operations
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "Compiling: $(notdir $<)"

$(NAME): $(OBJS_AUX) $(OBJ_MAIN)
	@make -sC libft
	@$(CC) $(OBJ_MAIN) $(OBJS_AUX) $(LIBFT) $(CFLAGS) -o $@
	@echo "\n[Compiled $(NAME) successfully]"

.PHONY: all clean fclean re

