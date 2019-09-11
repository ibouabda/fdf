# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: retounsi <retounsi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/06 21:31:16 by ibouabda          #+#    #+#              #
#    Updated: 2019/04/16 14:17:32 by retounsi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CFLAGS = -Wall -Werror -Wextra

SS =  ft_atoi.c\
	ft_itoa.c\
	ft_memset.c\
	ft_putstr.c\
	ft_strdup.c\
	ft_strmap.c\
	ft_strrchr.c\
	ft_bzero.c\
	ft_memalloc.c\
	ft_power.c\
	ft_putstr_fd.c\
	ft_strequ.c\
	ft_strmapi.c\
	ft_strsplit.c\
	ft_memccpy.c\
	ft_putchar.c\
	ft_strcat.c\
	ft_striter.c\
	ft_strncat.c\
	ft_strstr.c\
	ft_isalnum.c\
	ft_memchr.c\
	ft_putchar_fd.c\
	ft_strchr.c\
	ft_striteri.c\
	ft_strncmp.c\
	ft_strsub.c\
	ft_isalpha.c\
	ft_memcmp.c\
	ft_putendl.c\
	ft_strclr.c\
	ft_strjoin.c\
	ft_strncpy.c\
	ft_strtrim.c\
	ft_isascii.c\
	ft_memcpy.c\
	ft_putendl_fd.c\
	ft_strcmp.c\
	ft_strlcat.c\
	ft_strnequ.c\
	ft_tolower.c\
	ft_isdigit.c\
	ft_memdel.c\
	ft_putnbr.c\
	ft_strcpy.c\
	ft_strlen.c\
	ft_strnew.c\
	ft_toupper.c\
	ft_isprint.c\
	ft_memmove.c\
	ft_putnbr_fd.c\
	ft_strdel.c\
	ft_strlen_split.c\
	ft_strnstr.c\
	ft_lstnew.c\
	ft_lstdelone.c\
	ft_lstdel.c\
	ft_lstadd.c\
	ft_lstiter.c\
	ft_lstmap.c\
	ft_2dstrcmp.c\
	ft_2dstrnew.c\
	ft_3dputstr.c\
	ft_3dstrnew.c\
	ft_3dstrin.c\
	ft_strtolower.c\
	ft_strtoupper.c\
	ft_print_list.c\
	ft_strin.c\

OBJ_NAME = $(SS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ_NAME)
	gcc $(CFLAGS) -c $(SS)
	ar rc $(NAME) $(OBJ_NAME)
	ranlib $(NAME)
clean:
	/bin/rm -f $(OBJ_NAME)
fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
