FILE = main.cpp ClapTrap.cpp FragTrap.cpp DiamondTrap.cpp ScavTrap.cpp

NAME = DiamondTrap
HEADER = ClapTrap.hpp FragTrap.hpp DiamondTrap.hpp ScavTrap.hpp

OBJFILE = $(FILE:%.cpp=%.o)
CC = c++
FLAGS = -std=c++98 -Wall -Wextra -Werror
SHADOWFLAG = -Wshadow -Wno-shadow


all: $(NAME)

%.o: %.cpp $(HEADER)
	$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJFILE)
	$(CC) $(FLAGS) $(OBJFILE)  -o $(NAME)

clean:
	rm -f $(OBJFILE)

fclean: clean
	rm -f $(NAME)

re: clean all