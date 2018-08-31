#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ppellegr <ppellegr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/02/07 21:39:49 by ppellegr          #+#    #+#              #
#    Updated: 2018/05/15 19:34:41 by azulbukh         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME		= serveur

NAME1		= client

SRC0		= main_s.c maths.c ft_realloc.c

SRC1		= main_c.c ft_get_next_line.c

OBJ0		= $(SRC0:.c=.o)

OBJ1		= $(SRC1:.c=.o)

CFLAGS		= -Wextra -Wall -Werror -g3

CC			= cc

LIB_LIBFT	= libft/libft.a

INCLUDES	= -I libft/includes

all: $(NAME) $(NAME1)

$(NAME):
	make -C libft/
	$(CC) $(CFLAGS) -c $(SRC0) $(INCLUDES)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ0) $(LIB_LIBFT)

$(NAME1):
	$(CC) $(CFLAGS) -c $(SRC1) $(INCLUDES)
	$(CC) $(CFLAGS) -o $(NAME1) $(OBJ1) $(LIB_LIBFT)

clean:
	rm -f $(OBJ0)
	rm -f $(OBJ1)

fclean: clean
	rm -f $(NAME)
	rm -f $(NAME1)

re: fclean all

.PHONY: all clean fclean re
