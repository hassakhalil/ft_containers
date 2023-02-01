NAME = vector

SRC	= main.cpp 

OBJ	= $(SRC:.cpp=.o)

CPPFLAGS = -Wall -Wextra -Werror -std=c++98

$(NAME): $(OBJ)
	c++ $(OBJ) -o $(NAME)
	rm -rf $(OBJ)

all: $(NAME)

clean:
	rm -rf $(OBJ)
				
fclean:	clean
	rm -rf $(NAME)

re:	fclean all