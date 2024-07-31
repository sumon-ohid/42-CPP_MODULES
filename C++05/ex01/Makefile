# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/25 11:00:12 by msumon            #+#    #+#              #
#    Updated: 2024/07/31 15:54:11 by msumon           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= a.out
CPP		= c++
FLAGS	= -Wall -Werror -Wextra -std=c++98
HEADERS	= Bureaucrat.hpp Form.hpp
SRCS	= main.cpp Bureaucrat.cpp Form.cpp
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