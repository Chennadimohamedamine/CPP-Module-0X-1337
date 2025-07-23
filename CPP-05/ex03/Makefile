PROGRAM = Aform

SRCS = main.cpp Bureaucrat.cpp  AForm.cpp ShrubberyCreationForm.cpp  RobotomyRequestForm.cpp PresidentialPardonForm.cpp Intern.cpp

OBJS = $(SRCS:.cpp=.o)

CXX = c++

CFLAGS = -std=c++98 -Wall -Wextra -Werror

%.o:%.cpp Bureaucrat.hpp AForm.hpp ShrubberyCreationForm.hpp RobotomyRequestForm.hpp PresidentialPardonForm.hpp Intern.hpp 
	$(CXX) $(CFLAGS) -c $< -o $@

all: $(PROGRAM)

$(PROGRAM): $(OBJS)
	$(CXX) $(CFLAGS) -o $@ $^
clean:
	rm -f $(OBJS)
fclean: clean
	rm -f $(PROGRAM)
re: fclean all


