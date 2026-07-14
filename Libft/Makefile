# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lucferre <lucferre@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/07/11 00:25:40 by lucferre          #+#    #+#              #
#    Updated: 2026/07/13 22:07:30 by lucferre         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = cc
CFLAGS = -Wall -Werror -Wextra
SRC = ft_isalpha.c ft_isdigit.c ft_isalnum.c \
ft_isascii.c ft_isprint.c ft_strlen.c \
ft_memset.c ft_bzero.c ft_memcpy.c \
ft_memmove.c ft_strlcpy.c ft_strlcat.c \
ft_toupper.c ft_tolower.c ft_strchr.c \
ft_strrchr.c ft_strncmp.c ft_memchr.c \
ft_memcmp.c ft_strnstr.c ft_atoi.c \
ft_calloc.c ft_strdup.c ft_substr.c \
ft_strjoin.c ft_strtrim.c ft_split.c \
ft_itoa.c ft_strmapi.c ft_striteri.c \
ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c \
ft_putnbr_fd.c ft_lstnew.c ft_lstadd_front.c \
ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c \
ft_printf/formats.c ft_printf/ft_utoa.c ft_printf/ft_printf.c \
get_next_line/get_next_line_bonus.c get_next_line/get_next_line_utils_bonus.c
OBJ = $(SRC:.c=.o)
HEADER = libft.h

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

$(NAME): $(OBJ)
	@echo -n "\n$(YELLOW)Compiling Libft...$(DEF_COLOR)"
	@ar rcs $(NAME) $(OBJ)
	@echo "$(GREEN) [OK]$(DEF_COLOR)"
	@echo "$(GREEN)\033[40m\033[1mLibft compiled!$(DEF_COLOR)"

%.o: %.c $(HEADER)
	@echo -n "$(YELLOW)Compiling $<...$(DEF_COLOR)"
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo -n "$(GREEN) [OK]$(DEF_COLOR)             \r"

clean:
	@echo -n "$(CYAN)Removing object files...$(DEF_COLOR)"
	@rm -f $(OBJ) *.gch
	@echo "$(GREEN) [OK]$(DEF_COLOR)"

fclean: clean
	@echo -n "$(RED)Removing libft.a...$(DEF_COLOR)"
	@rm -f $(NAME)
	@echo "$(GREEN) [OK]$(DEF_COLOR)"

re: fclean all

.PHONY: all clean fclean re
