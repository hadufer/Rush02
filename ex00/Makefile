# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rahmed <rahmed@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/19 08:17:49 by rahmed            #+#    #+#              #
#    Updated: 2021/06/20 17:42:15 by rahmed           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = rush-02

SRC = *.c

all: $(NAME)

$(NAME):
	cc -Wall -Wextra -Werror -o $(NAME) $(SRC)

clean:
	rm -f *.o *.gch *.swp

fclean: clean
	rm -f $(NAME)

re: fclean all
