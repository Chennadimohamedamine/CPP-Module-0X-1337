FILE = main.cpp Zombie.cpp zombieHorde.cpp

NAME = zombieHorde

OBJFILE = $(FILE:.cpp=.o)
CC = c++
FLAGS = -std=c++98 -Wall -Wextra -Werror

all: $(NAME)

%.o: %.cpp Zombie.hpp
	$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJFILE)
	$(CC) $(FLAGS) $(OBJFILE) -o $(NAME)

clean:
	rm -f $(OBJFILE)

fclean: clean
	rm -f $(NAME)

re: clean all