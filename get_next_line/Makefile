# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mobouzar <mobouzar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/24 21:55:27 by mobouzar          #+#    #+#              #
#    Updated: 2019/05/07 00:35:55 by mobouzar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = gcc -Wall -Wextra  -Werror
SRC = *.c libft/*.c

all: $(NAME)
$(NAME):
	$(CC) -c $(SRC) -I.
	ar rc $(NAME) *.o
	$(CC) $(NAME)

clean:
	rm -rf *.o libft/*.o 

fclean: clean
	rm -rf *.a libft/*.a a.out a.out.dSYM

re: fclean all
