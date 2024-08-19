# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/13 09:50:29 by msumon            #+#    #+#              #
#    Updated: 2024/08/19 10:50:16 by msumon           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= PmergeMe
CXX			= c++
CXXFLAGS	= -Wall -Werror -Wextra -std=c++98
HEADERS		= PmergeMe.hpp
SRCS		= main.cpp PmergeMe.cpp
OBJS		= $(SRCS:.cpp=.o)
RM			= rm -rf

all:	$(NAME)

%.o: %.cpp $(HEADERS)
		$(CXX) $(CXXFLAGS) -c $< -o $@

$(NAME): $(OBJS)
		$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)


clean:
		$(RM) $(OBJS)

fclean: clean
		$(RM) $(NAME)
        
re:		fclean all

.PHONY: all clean fclean re
