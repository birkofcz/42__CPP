# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/13 10:45:26 by sbenes            #+#    #+#              #
#    Updated: 2023/08/28 14:28:05 by sbenes           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#color and formatting:
BOLD =	\033[1m
GREEN =	\033[32m
RED =	\033[31m
NC =	\033[0m

#name
NAME =		FragTrap

#compilation
CC =		c++
CFLAGS = 	-Wall -Wextra -Werror -std=c++98

#source files
SRC = 		main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp

all: $(NAME)

$(NAME): 
	@echo "$(BOLD)$(GREEN)[ Compiling ... ]$(NC)"
	@$(CC) $(CFLAGS) $(SRC) -o $(NAME)
	@echo "$(BOLD)$(GREEN)[ 🪄 Program ready! ]$(NC)"
	@./FragTrap

clean:
	@echo "$(BOLD)$(RED)[ 🔥 Removing program ]$(NC)"
	@rm -f $(NAME)

fclean:
	@echo "$(BOLD)$(RED)[ 🔥 Removing program ]$(NC)"
	@rm -f $(NAME)

re: fclean all

.PHONY: all re clean fclean