FILE = main.cpp Zombie.cpp zombieHorde.cpp

NAME = zombie

OBJFILE = $(FILE:.cpp=.o)
CC = g++
FLAGS = -std=c++98 -Wall -Wextra -Werror

all: $(NAME)

%.o: %.cpp Zombie.hpp
	$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(FILE)
	$(CC) $(FLAGS) $(FILE) -o $(NAME)

clean:
	rm -f $(OBJFILE)

fclean: clean
	rm -f $(NAME)

re: clean all