# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msumon < msumon@student.42vienna.com>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/02 22:52:22 by msumon            #+#    #+#              #
#    Updated: 2024/05/02 22:55:39 by msumon           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= megaphone
CC 		= c++
FLAGS 	= -Wall -Werror -Wextra -std=c++98
RM		= rm -rf

all: 	$(NAME)

$(NAME):
		@$(CC) $(FLAGS) megaphone.cpp -o $(NAME)
		@echo -compile success.

clean:
		@$(RM) $(NAME)
		@echo -remove success.

fclean:
		@$(RM) $(NAME)
		@echo -remove success.

re:		fclean all

.PHONY: clean fclean all