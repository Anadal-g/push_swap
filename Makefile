# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anadal-g <anadal-g@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/28 11:37:35 by anadal-g          #+#    #+#              #
#    Updated: 2024/01/11 16:31:16 by anadal-g         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
SOURCES = \
	main.c \
	push.c \
	swap.c \
	reverse_rotate.c \
	rotate.c \
	utils.c \
	errors.c \
	stack_init.c \
	stack_sorted.c \
	sort_stacks.c \
	init_a.c \

OBJS = $(SOURCES:%.c=%.o)
CC = gcc -g -O3 -fsanitize=address
CFLAGS = -Wall -Wextra -Werror
LIBFT = libft/libft.a

#COLORS

# WHITE = 0xFFFFFF
# ROJO = 0xFF0000
# VERDE = 0x00FF00
# AZUL = 0x0000FF
# AMARILLO = 0xFFFF00
# MAGENTA = 0xFF00FF
# CIAN = 0x00FFFF
# VIOLETA = 0x8A2BE2
# TURQUESA = 0x40E0D0
# CORAL = 0xFF7F50
# ESMERALDA = 0x2ECC71
# ZAFIRO = 0x082567
# LOLA_INDIGO = 0x4B0082
# AGUAMARINA = 0x7FFFD4
# MELOCOTON = 0xFFE5B4
# RUBI = 0xE0115F
# TOPACIO = 0x1E90FF
# ROSA_PALIDO = 0xFFB6C1
# FUCSIA = 0xFF00FF
# CHARTREUSE = 0x7FFF00
# TURQUESA_BRILLANTE = 0x00F5FF
# AMARANTO = 0xE52B50
# LILA = 0xB666D2
# AMARILLO_NEON = 0xDFFF00

all: $(NAME)

$(NAME) : $(OBJS)
	@make -sC libft
#	@echo "$(MELOCOTON)Compiling the PUSH_SWAP program.$(CLEAR)"
	@$(CC) $(CFLAGS) $(LIBFT) $(OBJS) -o $(NAME)
# @echo "$(VERDE)[OK]\n$(CLEAR)$(VERDE)Success!$(CLEAR)\n"


clean:
	rm -f $(OBJS)
	@make clean -sC libft

fclean: clean
	rm -f $(NAME)
	@make fclean -sC libft
re: fclean all

.PHONY: all clean fclean re