# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/08 10:26:53 by msumon            #+#    #+#              #
#    Updated: 2024/08/12 11:40:57 by msumon           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= 
CXX			= c++
CXXFLAGS	= -Wall -Werror -Wextra -std=c++98 -MMD -MP -pedantic
HEADERS		= 
SRCS		= main.cpp
OBJS		= $(SRCS:.cpp=.o)
DEPS		= $(OBJS:.o=.d)
RM			= rm -rf

all:	$(NAME)

-include $(DEPS)

$(NAME): $(OBJS)
		$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp $(HEADERS)
		$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
		$(RM) $(OBJS) $(DEPS)

fclean: clean
		$(RM) $(NAME)
        
re:		fclean all

.PHONY: all clean fclean re
