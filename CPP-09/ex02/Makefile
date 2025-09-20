PROGRAM =  PmergeMe

SRCS = main.cpp PmergeMe.cpp

OBJS = $(SRCS:.cpp=.o)

CXX = c++

CFLAGS = -std=c++98 -Wall -Wextra -Werror

%.o:%.cpp PmergeMe.hpp
	$(CXX) $(CFLAGS) -c $< -o $@

all: $(PROGRAM)

$(PROGRAM): $(OBJS)
	$(CXX) $(CFLAGS) -o $@ $^
clean:
	rm -f $(OBJS)
fclean: clean
	rm -f $(PROGRAM)

re: fclean all