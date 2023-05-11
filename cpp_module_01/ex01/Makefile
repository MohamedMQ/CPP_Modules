# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmaqbour <mmaqbour@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/13 11:14:34 by mmaqbour          #+#    #+#              #
#    Updated: 2023/09/13 11:21:28 by mmaqbour         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RED			= \033[31m
NO_COLOR	= \033[0m

NAME = zombie

OBJDIR = objs

SRCS = main.cpp zombieHorde.cpp Zombie.cpp

OBJS = $(SRCS:%.cpp=objs/%.o)

CC = c++

HEADERS = Zombie.hpp

CFLAGS = -Wall -Wextra -Werror -std=c++98

objs/%.o:./%.cpp $(HEADERS)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(RED)Create$(NO_COLOR) $@"

all : $(NAME)

$(NAME) : $(OBJDIR) $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $@
	@echo "$(RED)Generate$(NO_COLOR) $@"

$(OBJDIR) :
	@mkdir $@

clean :
	@rm -f $(OBJS)
	@echo "$(RED)Remove$(NO_COLOR) $(OBJS)"

fclean : clean
	@rm -f $(NAME)
	@echo "$(RED)Remove$(NO_COLOR) $(NAME)"

re :
	@make fclean
	@make all

.PHONY : all clean fclean re