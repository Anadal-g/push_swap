# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anadal-g <anadal-g@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/28 11:37:35 by anadal-g          #+#    #+#              #
#    Updated: 2024/11/18 16:41:49 by anadal-g         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

# SOURCE FILES
SRC_DIR		=	src/

SRC_FILES = errors.c \
			main.c \
			movements/push.c \
			movements/swap.c \
			movements/reverse_rotate.c \
			movements/rotate.c \
			utils.c \
			stack_init.c \
			stack_sorted.c \
			sort_stacks.c \
			init_a.c \
			stack_utils.c \

MOVEMENTS_FILES = 

SRC			=	$(addprefix $(SRC_DIR), $(SRC_FILES))

# OBJECT FILES
OBJ_DIR		= objs/
OBJ_FILES 	= $(SRC:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)

# COMPILER
CC		= gcc -g -O3 #-fsanitize=address
FLAGS	= -Wall -Wextra -Werror
INCLUDE = -I includes
RM		= rm -rf
LIBFT = libft/libft.a

# COLORS
RED		=	\033[91;1m
GREEN	=	\033[92;1m
YELLOW	=	\033[93;1m
BLUE	=	\033[94;1m
PINK	=	\033[95;1m
CLEAR	=	\033[0m

# MAKEFILE RULES

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR) $(OBJ_DIR)/movements
	$(CC) $(FLAGS) -c $< -o $@


all: $(NAME)

$(NAME) : $(OBJ_FILES)
	@make -sC libft
	@echo "$(GREEN)Compiling the push_swap program.$(CLEAR)"
	$(CC) $(FLAGS) $(OBJ_FILES) -o $(NAME) $(INCLUDE) -Llibft -lft
	@echo "$(GREEN)[OK]\n$(CLEAR)$(GREEN)Success!$(CLEAR)\n"
	
clean:
	@echo "$(BLUE)Removing compiled files.$(CLEAR)"
	$(RM) $(OBJ_DIR)
	@make -sC libft/ clean
	@echo "$(BLUE)Object files removed correctly\n$(CLEAR)"

fclean: clean
	@echo "$(BLUE)Removing exec. files.$(CLEAR)"
	$(RM) $(NAME)
	@make -sC libft/ fclean
	@echo "$(BLUE)Object files and binary removed correctly\n$(CLEAR)"

re: fclean all

.PHONY: all clean fclean re  