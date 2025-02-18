NAME = easyfind

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

RM = rm -rf
SRCS = ./main.cpp

OBJS = $(SRCS:.cpp=.o)

RESET		= \033[0m
GREEN   	= \033[32;01m
BLUE		= \033[34;01m
WHITE		= \033[1;37m

all: $(NAME)

$(NAME): $(OBJS)
	@echo "$(BLUE)Compiling $(NAME)...$(RESET)"
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)
	@echo "$(GREEN) Build successful!$(RESET)"

clean:
	@echo "$(WHITE) Cleaning object files...$(RESET)"
	@$(RM) $(OBJS)

fclean: clean
	@echo "$(WHITE) Cleaning executable...$(RESET)"
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
