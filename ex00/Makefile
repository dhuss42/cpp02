CC = c++
FLAGS = -Wall -Werror -Wextra
CPPFILES = main.cpp\
	Fixed.cpp
OFILES = $(CPPFILES:.cpp=.o)
NAME = My_First_Class_in_Orthodox_Canonical_Form

$(NAME) : $(OFILES)
	$(CC) $(FLAGS) $(OFILES) -o $(NAME)

all: $(NAME)

clean:
	rm -rf $(OFILES)

fclean:	clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean