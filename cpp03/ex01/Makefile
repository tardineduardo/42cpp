NAME	= scav

CC		= g++
CFLAGS= -std=c++98 -Wall -Wextra -Werror -I.

SRCS	= main.cpp ClapTrap.cpp ScavTrap.cpp

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