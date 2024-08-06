# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/06 11:59:29 by msumon            #+#    #+#              #
#    Updated: 2024/08/06 21:43:55 by msumon           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= identifier
CXX			= c++
CXXFLAGS	= -Wall -Werror -Wextra -std=c++98
OBJS		= $(SRCS:.cpp=.o) 
RM			= rm -rf

HEADERS		= Base.hpp A.hpp B.hpp C.hpp
SRCS		= main.cpp Base.cpp A.cpp B.cpp C.cpp

all:	$(NAME)

$(NAME): $(OBJS)
		$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean:
		$(RM) $(OBJS)

fclean: clean
		$(RM) $(NAME)
		
re:		fclean all

.PHONY: all clean fclean re
