# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vonpr <vonpr@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/03/30 03:55:22 by vonpr             #+#    #+#              #
#    Updated: 2026/04/10 16:03:25 by vonpr            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = philosopher
CC          = cc  
CFLAGS      = -Wall -Wextra -Werror -pthread -g

SRCS        =	utils.c \
				monitor.c \
				parsing.c \
				routines.c \
				simulation.c \
				initializing.c \
				philosopher.c

OBJS        = $(SRCS:.c=.o)

GREEN       = \033[0;32m
RESET       = \033[0m

all: $(NAME)

$(NAME): $(OBJS)
	@echo "Compiling $(NAME)..."
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "$(GREEN)$(NAME) ready!$(RESET)"

%.o: %.c
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@rm -f $(OBJS)
	@echo "Object files removed."

fclean: clean
	@rm -f $(NAME)
	@echo "Executable removed."

re: fclean all

.PHONY: all clean fclean re