NAME      = horde

CXX       = g++
CXXFLAGS  = -std=c++98 -Wall -Wextra -Werror -g -I.

SRCS      = main.cpp Zombie.cpp zombieHorde.cpp
OBJS      = $(SRCS:.cpp=.o)

# Auto header dependencies
CXXFLAGS += -MMD -MP
DEPS      = $(OBJS:.o=.d)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS) $(DEPS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

-include $(DEPS)