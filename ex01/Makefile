CC = c++
FLAGS = -Wall -Werror -Wextra
CPPFILES = main.cpp\
	Fixed.cpp
OFILES = $(CPPFILES:.cpp=.o)
NAME = Towards_a_more_useful_fixed-point_number_class

$(NAME) : $(OFILES)
	$(CC) $(FLAGS) $(OFILES) -o $(NAME)

all: $(NAME)

clean:
	rm -rf $(OFILES)

fclean:	clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean