
FILE =  main.cpp Animal.cpp Dog.cpp Cat.cpp WrongAnimal.cpp  WrongCat.cpp Brain.cpp

HEADER = Cat.hpp Animal.hpp Dog.hpp WrongAnimal.hpp WrongCat.hpp Brain.hpp

NAME = Abstract

OBJFILE = $(FILE:%.cpp=%.o)
CC = c++
FLAGS = -std=c++98 -Wall -Wextra -Werror

all: $(NAME)

%.o: %.cpp $(HEADER)
	$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJFILE)
	$(CC) $(FLAGS) $(OBJFILE) -o $(NAME)

clean:
	rm -f $(OBJFILE)

fclean: clean
	rm -f $(NAME)

re: clean all