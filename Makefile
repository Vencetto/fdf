# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vzomber <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/08 18:34:19 by vzomber           #+#    #+#              #
#    Updated: 2018/03/08 18:34:20 by vzomber          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC =	src/main.c \
		src/parser.c \
		src/painter.c \
		src/buttons.c \
		src/movement.c \
		src/center.c \
		src/rotations.c \
		src/additional.c

OBJ =	main.o \
		parser.o \
		painter.o \
		buttons.o \
		movement.o \
		center.o \
		rotations.o \
		additional.o

FLAGS = -Wall -Wextra -Werror -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(OBJ): $(SRC) includes/fdf.h
	@gcc  -c $(SRC) 

$(NAME): $(OBJ) includes/fdf.h
	@make -C libft
	@gcc $(FLAGS) $(OBJ) -o $(NAME) -L./libft -lft 
	@echo "make for fdf: Done"

clean:
	@rm -f $(OBJ)
	@make -C libft clean

fclean: clean
	@rm -f $(NAME)
	@make -C libft fclean

re: fclean all