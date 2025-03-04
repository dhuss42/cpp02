# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dhuss <dhuss@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/04 10:22:10 by dhuss             #+#    #+#              #
#    Updated: 2025/03/04 10:22:11 by dhuss            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = c++
FLAGS = -Wall -Werror -Wextra
CPPFILES = main.cpp\
	Fixed.cpp
OFILES = $(CPPFILES:.cpp=.o)
NAME = BSP

$(NAME) : $(OFILES)
	$(CC) $(FLAGS) $(OFILES) -o $(NAME)

all: $(NAME)

clean:
	rm -rf $(OFILES)

fclean:	clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean