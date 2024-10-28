#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fatmanurcetintas <fatmanurcetintas@stud    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/23 15:49:03 by facetint          #+#    #+#              #
#    Updated: 2024/10/29 01:45:56 by fatmanurcet      ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = clapTrap

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -Wshadow -std=c++98
RM = rm -rf

SRCS = ./main.cpp ./ClapTrap.cpp

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
