# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: idris <idris@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/11 17:46:29 by idris             #+#    #+#              #
#    Updated: 2019/09/16 14:02:42 by idris            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

CFLAGS = -Wall -Werror -Wextra

MLX2 = -framework OpenGL -framework AppKit

PATHFILE = ./libft

CC = gcc

SRC_NAME = main.c get_next_line.c read_file.c ft_fdf.c table_too_img.c mlx_img.c libft/libft.a minilibx_macos/libmlx.a

OBJ_NAME = $(SRC_NAME:.c=.o)

all: $(NAME)

$(LIB):
	make -C $(PATHFILE)

$(NAME): $(LIB) $(OBJ_NAME) libft/libft.a
	$(CC) $(MLX) -o $(NAME) $(SRC_NAME)

clean:
	rm -f $(OBJ_NAME)
	make clean -C $(PATHFILE)

fclean:
	rm -f $(OBJ_NAME)
	rm -f $(NAME)
	make fclean -C $(PATHFILE)

re: fclean all
