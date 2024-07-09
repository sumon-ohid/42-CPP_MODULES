# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/05 21:52:43 by msumon            #+#    #+#              #
#    Updated: 2024/07/09 16:06:12 by msumon           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= TheJobOfYourDreams
CPP		= c++
FLAGS	= -Wall -Werror -Wextra -std=c++98
HEADERS	= Account.hpp
SRCS	= Account.cpp tests.cpp
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