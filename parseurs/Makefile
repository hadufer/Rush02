# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rahmed <rahmed@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/19 08:17:49 by rahmed            #+#    #+#              #
#    Updated: 2021/06/19 08:31:24 by rahmed           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = rush-02

SRC = main.c parsing.c

all: $(NAME)

$(NAME):
	cc -Wall -Wextra -Werror -o $(NAME) $(SRC)

clean:
	./rm -f *.o

fclean: clean
	./rm -f $(NAME)

re: fclean all
