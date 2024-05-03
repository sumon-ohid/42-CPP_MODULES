# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msumon < msumon@student.42vienna.com>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/03 08:58:12 by msumon            #+#    #+#              #
#    Updated: 2024/05/03 11:25:19 by msumon           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= phonebook
CC		= c++
FLAGS	= -Wall -Werror -Wextra -std=c++98
HEADERS	= contact.hpp phonebook.hpp
SRCS	= srcs/main.cpp
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