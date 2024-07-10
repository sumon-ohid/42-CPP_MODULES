# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/03 08:58:12 by msumon            #+#    #+#              #
#    Updated: 2024/07/10 15:24:18 by msumon           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= bsp
CPP		= c++
FLAGS	= -Wall -Werror -Wextra -std=c++98
HEADERS	= Fixed.hpp Point.hpp
SRCS	= main.cpp Fixed.cpp Point.cpp bsp.cpp

OBJS	= $(SRCS:.cpp=.o)
RM		= rm -rf

all:	$(NAME)

$(NAME): $(OBJS)
		$(CPP) $(FLAGS) $(OBJS) -o $(NAME)

clean:
		$(RM) $(OBJS)

fclean: clean
		$(RM) $(NAME)
		
re:		fclean all

.PHONY: all clean fclean re