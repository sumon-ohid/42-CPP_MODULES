# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/06 11:59:29 by msumon            #+#    #+#              #
#    Updated: 2024/08/06 20:17:17 by msumon           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= serialize
CXX			= c++
CXXFLAGS	= -Wall -Werror -Wextra -std=c++98
HEADERS		= Serializer.hpp
SRCS		= main.cpp Serializer.cpp
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
