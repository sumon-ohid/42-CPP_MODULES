# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/08 10:26:53 by msumon            #+#    #+#              #
#    Updated: 2024/08/08 12:10:41 by msumon           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= array
CXX			= c++
CXXFLAGS	= -Wall -Werror -Wextra -std=c++98
HEADERS		= Array.hpp
SRCS		= main.cpp
OBJS		= $(SRCS:.cpp=.o)
RM			= rm -rf

all:	$(NAME)

$(NAME): $(OBJS)
		$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean:
		$(RM) $(OBJS)

fclean: clean
		$(RM) $(NAME)
		
re:		fclean all

.PHONY: all clean fclean re
