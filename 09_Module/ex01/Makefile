# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/04 09:20:07 by sbenes            #+#    #+#              #
#    Updated: 2023/09/25 16:22:46 by sbenes           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#color and formatting:
BOLD =	\033[1m
GREEN =	\033[32m
RED =	\033[31m
NC =	\033[0m

#name
NAME =		RPN

#compilation
CC =		c++
CFLAGS = 	-Wall -Wextra -Werror -std=c++98

#source files
SRC = 		RPN.cpp main.cpp 
all: $(NAME)

$(NAME): 
	@echo "$(BOLD)$(GREEN)[ Compiling ... ]$(NC)"
	@$(CC) $(CFLAGS) $(SRC) -o $(NAME)
	@echo "$(BOLD)$(GREEN)[ 🪄 Program ready! ]$(NC)"
	@echo "\n$(BOLD)$(GREEN)[ 📖 Usage ]$(NC)"
	@echo "./RPN <reverse polish notation expression>"
	@echo "./RPN eval - subject & evalsheet tests mode\n"


clean:
	@echo "$(BOLD)$(RED)[ 🔥 Removing program ]$(NC)"
	@rm -f $(NAME)

fclean:
	@echo "$(BOLD)$(RED)[ 🔥 Removing program ]$(NC)"
	@rm -f $(NAME)

re: fclean all

.PHONY: all re clean fclean