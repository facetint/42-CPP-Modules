# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: facetint <facetint@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/08 19:34:14 by facetint          #+#    #+#              #
#    Updated: 2024/10/10 21:05:33 by facetint         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Zombie

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -rf

SRCS = ./main.cpp ./Zombie.cpp ./zombieHorde.cpp

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
