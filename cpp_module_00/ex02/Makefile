# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmaqbour <mmaqbour@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/12 14:12:31 by mmaqbour          #+#    #+#              #
#    Updated: 2023/09/12 14:12:32 by mmaqbour         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RED			= \033[31m
NO_COLOR	= \033[0m

NAME = account

SRCS = Account.cpp tests.cpp

OBJS = $(SRCS:%.cpp=%.o)

CC = c++

HEADERS = Account.hpp

CFLAGS = -Wall -Wextra -Werror -std=c++98

%.o:%.cpp $(HEADERS)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(RED)Create$(NO_COLOR) $@"

all : $(NAME)

$(NAME) : $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "$(RED)Generate$(NO_COLOR) $(NAME)"

clean :
	@echo "$(RED)Remove$(NO_COLOR) $(OBJS)"
	@rm -f $(OBJS)

fclean : clean
	@echo "$(RED)Remove$(NO_COLOR) $(NAME)"
	@rm -f $(NAME)

re :
	make fclean
	make all

.PHONY : all clean fclean re