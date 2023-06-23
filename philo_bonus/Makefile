# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rel-isma <rel-isma@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/14 18:23:16 by rel-isma          #+#    #+#              #
#    Updated: 2023/06/23 23:11:44 by rel-isma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror

SOURCES = philos_bonus.c create_philosophers.c ft_atoi.c ft_strjoin.c ft_check_error.c  ft_init_bonus.c myroutine.c phillo_needs.c phillo_needs2.c ft_check_try.c
OBJECTS = $(SOURCES:%.c=obj/%.o)
NAME = philo_bonus

all: $(NAME)

obj/%.o: src_b/%.c  src_b/philos_bonus.h | obj
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf "\033[0;36mCompiling $<\033[0m\n"
	@sleep 0.5

obj:
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
	@rm -f $(NAME)
	@printf "\033[0;32mExecutable cleaned.\033[0m\n"

re: fclean all

#.PHONY: all clean fclean re obj
