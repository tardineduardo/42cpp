#------------------------------------------------------------------------------#
#                                  GENERICS                                    #
#------------------------------------------------------------------------------#

# Special variables
.DEFAULT_GOAL := all
.DELETE_ON_ERROR:
.PHONY: all bonus clean fclean re

# Hide calls
VERBOSE ?= TRUE
ifeq ($(VERBOSE),TRUE)
    HIDE =
else
    HIDE = @
endif

#------------------------------------------------------------------------------#
#                                VARIABLES                                     #
#------------------------------------------------------------------------------#

# Compiler and flags
CC      =   g++



CFLAGS  =   -std=c++98 -Wall -Wextra -Werror -g -O0 -fno-omit-frame-pointer -I.
RM      =   rm -rf

# Dir and file names
NAME    =   phonebook
SRCS    =   phonebook.cpp
OBJS    =   $(SRCS:.cpp=.o)
INC     =   $(wildcard *.hpp)

#------------------------------------------------------------------------------#
#                                 TARGETS                                      #
#------------------------------------------------------------------------------#

all: $(NAME)

# Generates output file
$(NAME): $(OBJS)
	$(HIDE)$(CC) $(CFLAGS) $(OBJS) -o $@

# Compiles sources into objects
%.o: %.cpp $(INC)
	$(HIDE)$(CC) $(CFLAGS) -c $< -o $@

# Removes objects
clean:
	$(HIDE)$(RM) $(OBJS)

# Removes objects and executables
fclean: clean
	$(HIDE)$(RM) $(NAME)

# Removes objects and executables and remakes
re: fclean all

