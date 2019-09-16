# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ibouabda <ibouabda@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/11 17:46:29 by idris             #+#    #+#              #
#    Updated: 2019/09/16 15:19:56 by ibouabda         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

# CFLAGS = -Wall -Werror -Wextra

MLX = -framework OpenGL -framework AppKit

PATHFILE = ./libft

CC = gcc

SRC_NAME = main.c get_next_line.c read_file.c ft_fdf.c table_too_img.c mlx_img.c

OBJ_NAME = $(SRC_NAME:.c=.o)

LIB = $(PATHFILE)/libft.a

LIBMLX = ./minilibx_macos/libmlx.a

all: $(NAME)

$(LIB):
	make -C $(PATHFILE)

$(LIBMLX):
	make -C ./minilibx_macos

$(NAME): $(LIB) $(LIBMLX) $(OBJ_NAME)
	$(CC) -c $(SRC_NAME)
	$(CC) $(MLX) -o $(NAME) $(OBJ_NAME) libft/libft.a minilibx_macos/libmlx.a

# $(NAME): $(LIB) $(OBJ_NAME) libft/libft.a
#	$(CC) $(CFLAGS) -c $(SRC_NAME)
#	$(CC) -o $(NAME) $(OBJ_NAME) libft/libft.a

clean:
	rm -f $(OBJ_NAME)
	make clean -C $(PATHFILE)

fclean:
	rm -f $(OBJ_NAME)
	rm -f $(NAME)
	make fclean -C $(PATHFILE)

re: fclean all
