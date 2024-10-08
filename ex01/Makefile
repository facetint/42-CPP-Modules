# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: facetint <facetint@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/08 19:34:14 by facetint          #+#    #+#              #
#    Updated: 2024/10/08 19:34:15 by facetint         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Zombie

CCXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -rf

SRCS = ./main.cpp ./Zombie.cpp ./zombieHorde.cpp

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CCXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CCXX) $(CXXFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
