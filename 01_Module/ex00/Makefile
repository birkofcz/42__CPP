# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/28 16:42:15 by sbenes            #+#    #+#              #
#    Updated: 2023/08/07 13:16:20 by sbenes           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


#color and formatting:
BOLD =	\033[1m
GREEN =	\033[32m
RED =	\033[31m
NC =	\033[0m

#name
NAME =		brainz

#compilation
CC =		c++
CFLAGS = 	-Wall -Wextra -Werror -std=c++98

#source files
SRC = 		main.cpp Zombie.cpp newZombie.cpp randomChump.cpp

all: $(NAME)

$(NAME): 
	@echo "$(BOLD)$(GREEN)[ Compiling ... ]$(NC)"
	@$(CC) $(CFLAGS) $(SRC) -o $(NAME)
	@echo "$(BOLD)$(GREEN)[ 🪄 Program ready! ]$(NC)"

clean:
	@echo "$(BOLD)$(RED)[ 🔥 Removing program ]$(NC)"
	@rm -f $(NAME)

fclean:
	@echo "$(BOLD)$(RED)[ 🔥 Removing program ]$(NC)"
	@rm -f $(NAME)

re: fclean all

.PHONY: all re clean fclean