# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lucferre <lucferre@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/07/13 22:34:11 by lucferre          #+#    #+#              #
#    Updated: 2026/07/15 22:38:08 by lucferre         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFLAGS = -Wall -Werror -Wextra
LIBFT_DIR = ./Libft
LIBFT = $(LIBFT_DIR)/libft.a
SRC = main.c sorts.c
OBJ = $(SRC:.c=.o)
HEADER = push_swap.h

# Colors

DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
ORANGE = \033[0;33m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	@cc $(CFLAGS) $(OBJ) -L$(LIBFT_DIR) -lft -o $(NAME)
	@echo "\n$(GREEN)$(NAME) compiled! $(DEF_COLOR)\n"

%.o: %.c $(HEADER)
	@echo -n "$(YELLOW)Compiling: $< $(DEF_COLOR)"
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(GREEN)[OK] $(DEF_COLOR)"

$(LIBFT):
	@echo -n "$(YELLOW)\nCompiling Libft $(DEF_COLOR)"
	@make -C $(LIBFT_DIR) all --no-print-directory
	@echo "$(GREEN)[OK] $(DEF_COLOR)"
	@echo "$(GREEN)Libft compiled\n $(DEF_COLOR)"

clean:
	@echo -n "$(CYAN)\nRemoving object files $(DEF_COLOR)"
	@rm -f $(OBJ) *.gch
	@make -C $(LIBFT_DIR) clean --no-print-directory
	@echo "$(GREEN)[OK] $(DEF_COLOR)"

fclean: clean
	@echo -n "$(RED)Removing $(NAME)... $(DEF_COLOR)"
	@rm -f $(NAME)
	@make -C $(LIBFT_DIR) fclean --no-print-directory
	@echo "$(GREEN)[OK] $(DEF_COLOR)"

re: fclean all

.PHONY: all clean fclean re