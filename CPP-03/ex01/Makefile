FILE = main.cpp ClapTrap.cpp ScavTrap.cpp

NAME = ScavTrap

OBJFILE = $(FILE:%.cpp=%.o)
CC = c++
FLAGS = -std=c++98 -Wall -Wextra -Werror

all: $(NAME)

%.o: %.cpp 
	$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJFILE)
	$(CC) $(FLAGS) $(OBJFILE) -o $(NAME)

clean:
	rm -f $(OBJFILE)

fclean: clean
	rm -f $(NAME)

re: clean all