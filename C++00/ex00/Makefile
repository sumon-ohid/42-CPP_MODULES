# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/02 22:52:22 by msumon            #+#    #+#              #
#    Updated: 2024/07/05 21:53:53 by msumon           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= Megaphone
CC		= c++
FLAGS	= -Wall -Werror -Wextra -std=c++98
SRCS	= megaphone.cpp
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