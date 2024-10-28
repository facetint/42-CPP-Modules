NAME = scavTrap

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -Wshadow -std=c++98
RM = rm -rf

SRCS = ./main.cpp ./ClapTrap.cpp ./ScavTrap.cpp

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
