NAME	= bureaucrats1

CC		= g++
CFLAGS  = -std=c++98 -g -Wall -Wextra -Werror -I.

SRCS	= main.cpp \
		  Bureaucrat.cpp \
		  Bureaucrat2.cpp \
		  Form.cpp \
		  AForm.cpp \
		  ShrubberyCreationForm.cpp \
		  RobotomyRequestForm.cpp \
		  PresidentialPardonForm.cpp \
		  messages.cpp

OBJS	= $(SRCS:.cpp=.o)

RM		= rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re