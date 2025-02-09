FILE = main.cpp Harl.cpp

NAME = harl

OBJFILE = $(FILE:%.cpp=%.o)
CC = g++
FLAGS = -std=c++98 -Wall -Wextra -Werror

all: $(NAME)

%.o: %.cpp Harl.hpp
	$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJFILE)
	$(CC) $(FLAGS) $(FILE) -o $(NAME)

clean:
	rm -f $(OBJFILE)

fclean: clean
	rm -f $(NAME)

re: clean all