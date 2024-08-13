# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/08 10:26:53 by msumon            #+#    #+#              #
#    Updated: 2024/08/13 09:43:54 by msumon           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= span
CXX			= c++
CXXFLAGS	= -Wall -Werror -Wextra -std=c++98
HEADERS		= Span.hpp
SRCS		= main.cpp Span.cpp
OBJS		= $(SRCS:.cpp=.o)
RM			= rm -rf

all:	$(NAME)

$(NAME): $(OBJS)
		$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp $(HEADERS)
		$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
		$(RM) $(OBJS)
fclean: clean
		$(RM) $(NAME)
        
re:		fclean all

.PHONY: all clean fclean re
