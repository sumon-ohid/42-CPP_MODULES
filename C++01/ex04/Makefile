# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/03 08:58:12 by msumon            #+#    #+#              #
#    Updated: 2024/07/09 15:06:38 by msumon           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= filewriter
CC		= c++
FLAGS	= -Wall -Werror -Wextra -std=c++98
HEADERS	= FileWriter.hpp
SRCS	= main.cpp FileWriter.cpp

OBJS	= $(SRCS:.cpp=.o)
RM		= rm -rf

all:	$(NAME)

$(NAME): $(OBJS)
		$(CC) $(FLAGS) $(OBJS) -o $(NAME)

clean:
		$(RM) $(OBJS)

fclean: clean
		$(RM) $(NAME)
		
re:		fclean all

.PHONY: all clean fclean re