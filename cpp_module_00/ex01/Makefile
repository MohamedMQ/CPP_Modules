# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmaqbour <mmaqbour@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/12 14:11:42 by mmaqbour          #+#    #+#              #
#    Updated: 2023/09/12 14:11:47 by mmaqbour         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RED			= \033[31m
NO_COLOR	= \033[0m

NAME = phonebook

SRCS = main.cpp PhoneBook.cpp Contact.cpp

OBJS = $(SRCS:%.cpp=%.o)

CC = c++

HEADERS = PhoneBook.hpp Contact.hpp

CFLAGS = -Wall -Wextra -Werror -std=c++98

%.o:%.cpp $(HEADERS)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(RED)Create$(NO_COLOR) $@"

all : $(NAME)

$(NAME) : $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "$(RED)Generate$(NO_COLOR) $(NAME)"

clean :
	@rm -f $(OBJS)
	@echo "$(RED)Remove$(NO_COLOR) $(OBJS)"

fclean : clean
	@rm -f $(NAME)
	@echo "$(RED)Remove$(NO_COLOR) $(NAME)"

re :
	make fclean
	make all

.PHONY : all clean fclean re