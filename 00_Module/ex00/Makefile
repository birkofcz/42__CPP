# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/13 14:53:31 by sbenes            #+#    #+#              #
#    Updated: 2023/07/13 15:19:52 by sbenes           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#color and formatting:
BOLD =	\033[1m
GREEN =	\033[32m
RED =	\033[31m
NC =	\033[0m

#name
NAME =		megaphone

#compilation
CC =		c++
CFLAGS = 	-Wall -Wextra -Werror -std=c++98

#source files
SRC = 		megaphone.cpp

all: $(NAME)

$(NAME): 
	@echo "$(BOLD)$(GREEN)[ Compiling ... ]$(NC)"
	@$(CC) $(CFLAGS) $(SRC) -o $(NAME)
	@echo "$(BOLD)$(GREEN)[ 🪄 Program ready! ]$(NC)"
	@echo ""
	@echo "$(RED)       ██ ███    ███ ███████  ██████   █████  ██████  ██   ██  ██████  ███    ██ ███████ $(NC)"
	@echo "      ██  ████  ████ ██      ██       ██   ██ ██   ██ ██   ██ ██    ██ ████   ██ ██      "
	@echo "     ██   ██ ████ ██ █████   ██   ███ ███████ ██████  ███████ ██    ██ ██ ██  ██ █████   "
	@echo "    ██    ██  ██  ██ ██      ██    ██ ██   ██ ██      ██   ██ ██    ██ ██  ██ ██ ██      "
	@echo "██ ██     ██      ██ ███████  ██████  ██   ██ ██      ██   ██  ██████  ██   ████ ███████ "
	@echo "                                                                                        	"
                                                                                         


clean:
	@echo "$(BOLD)$(RED)[ 🔥 Removing program ]$(NC)"
	@rm -f $(NAME)

fclean:
	@echo "$(BOLD)$(RED)[ 🔥 Removing program ]$(NC)"
	@rm -f $(NAME)

re: fclean all

.PHONY: all re clean fclean