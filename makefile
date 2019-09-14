# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: retounsi <retounsi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/11 17:46:29 by idris             #+#    #+#              #
#    Updated: 2019/09/14 10:54:58 by retounsi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

CFLAGS = -L /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit

PATHFILE = ./libft

CC = gcc -I /usr/local/include/

SRC_NAME = main.c get_next_line.c read_file.c ft_fdf.c libft/libft.a

OBJ_NAME = $(SRC_NAME:.c=.o)

all: $(NAME)

.libft:
	make -C $(PATHFILE)

$(NAME): .libft $(OBJ_NAME) libft/libft.a
	$(CC) $(SRC_NAME) $(CFLAGS)

clean:
	rm -f $(OBJ_NAME)
	make clean -C $(PATHFILE)

fclean:
		rm -f $(OBJ_NAME)
		rm -f $(NAME)
		make fclean -C $(PATHFILE)

re: fclean all
