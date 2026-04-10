# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vonpr <vonpr@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/04/07 22:33:37 by vonpr             #+#    #+#              #
#    Updated: 2026/04/10 15:53:17 by vonpr            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = fractol
CC          = cc
CFLAGS      = -Wall -Wextra -Werror -g
INCLUDES    = -I. -I./minilibx 
MLX_FLAGS   = -L./minilibx -lmlx -L/usr/lib -lXext -lX11 -lm

SRCS        = fractol.c \
              fractal_init.c \
              render.c \
			  render_utils.c \
              math_utils.c \
			  events.c \
              utils.c

OBJS        = $(SRCS:.c=.o)

GREEN       = \033[0;32m
RESET       = \033[0m

all: $(NAME)

$(NAME): $(OBJS)
	@echo "Compiling $(NAME)..."
	@$(CC) $(CFLAGS) $(OBJS) $(MLX_FLAGS) -o $(NAME)
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