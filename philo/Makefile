# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rel-isma <rel-isma@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/14 18:23:16 by rel-isma          #+#    #+#              #
#    Updated: 2023/06/23 21:04:07 by rel-isma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror

SOURCES = phillo.c phillo_needs.c ft_check_error.c  create_philosophers.c  ft_atoi.c phillo_needs2.c myroutine.c ft_init.c 

OBJECTS = $(SOURCES:%.c=obj/%.o)

NAME = philo

all: $(NAME)

obj/%.o: src/%.c  src/phillo.h | obj
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf "\033[0;36mCompiling $<\033[0m\n"
	@sleep 0.5

obj :
	@mkdir obj
		
$(NAME): $(OBJECTS)
	@printf "\033[0;32mLinking...\033[0m\n"
	@sleep 0.5
	@$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME)
	@printf "\033[0;32m$(NAME) compilation completed.\033[0m\n"

clean:
	@printf "\033[0;31mCleaning object files...\033[0m\n"
	@sleep 0.5
	@rm -rf obj
	@printf "\033[0;32mObject files cleaned.\033[0m\n"
	@sleep 0.5
fclean: clean
	@printf "\033[0;31mCleaning executable...\033[0m\n"
	@sleep 0.5
	@rm -rf $(NAME)
	@printf "\033[0;32mExecutable cleaned.\033[0m\n"
re: fclean all

.PHONY :