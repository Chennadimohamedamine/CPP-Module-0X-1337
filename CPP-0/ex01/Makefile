PROGRAM = PhoneBook

SRCS = PhoneBook.cpp Contact.cpp main.cpp utils.cpp 

OBJS = $(SRCS:.cpp=.o)
CXX = g++
CFLAGS = -std=c++98 -Wall -Wextra -Werror

all: $(PROGRAM)

%.o:%.cpp Contact.hpp PhoneBook.hpp utils.hpp
	$(CXX) $(CFLAGS) -c $< -o $@

$(PROGRAM): $(OBJS)
	$(CXX) $(CFLAGS) $(OBJS) -o $(PROGRAM)
clean:
	rm -f $(OBJS)
fclean: clean
	rm -f $(PROGRAM)
re: fclean all

.PHONY: all clean fclean re