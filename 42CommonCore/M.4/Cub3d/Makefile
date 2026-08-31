# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vonpr <vonpr@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/08/31 01:09:26 by vonpr             #+#    #+#              #
#    Updated: 2026/08/31 01:15:38 by vonpr            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= cub3d

CC			= cc
CFLAGS		= -Wall -Wextra -Werror -g
RM			= rm -f

MLX_DIR		= minilibx
MLX_LIB		= $(MLX_DIR)/libmlx.a
MLX_FLAGS	= -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

INCLUDES	= -I. -I$(MLX_DIR)

OBJ_DIR		= obj

SRCS		=	main.c \
				fake_parse.c \
				clean/cleanup.c \
				init/event.c \
				init/init_utils.c \
				init/init.c \
				render/color.c \
				render/dda.c \
				render/movement.c \
				render/render.c

OBJS		= $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

COUNT_FILE	= $(OBJ_DIR)/.count
TOTAL		= $(words $(SRCS))

GREEN		= \033[0;32m
BOLD_GREEN	= \033[1;32m
RESET		= \033[0m

all: init_progress $(NAME)

init_progress:
	@mkdir -p $(OBJ_DIR)
	@rm -f $(COUNT_FILE)
	@echo "$(BOLD_GREEN)🌱 growing $(NAME)...$(RESET)"

$(NAME): $(MLX_LIB) $(OBJS)
	@$(CC) $(OBJS) $(MLX_FLAGS) -o $(NAME)
	@printf "\n$(BOLD_GREEN)🌿 $(NAME) is ready!$(RESET)\n"

$(MLX_LIB):
	@if [ -f $(MLX_DIR)/Makefile ]; then \
		$(MAKE) -s -C $(MLX_DIR) > /dev/null; \
	fi

$(OBJ_DIR)/%.o: %.c cub.h
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	@n=$$(( $$(cat $(COUNT_FILE) 2>/dev/null || echo 0) + 1 )); \
	echo $$n > $(COUNT_FILE); \
	percent=$$(( n * 100 / $(TOTAL) )); \
	filled=$$(( percent / 5 )); \
	empty=$$(( 20 - filled )); \
	bar=""; i=0; \
	while [ $$i -lt $$filled ]; do bar="$${bar}#"; i=$$((i + 1)); done; \
	sp=""; i=0; \
	while [ $$i -lt $$empty ]; do sp="$${sp}."; i=$$((i + 1)); done; \
	printf "\r\033[K$(GREEN)  [%s%s] %3d%%$(RESET)" "$$bar" "$$sp" "$$percent"

clean:
	@$(RM) -r $(OBJ_DIR)
	@if [ -f $(MLX_DIR)/Makefile ]; then $(MAKE) -s -C $(MLX_DIR) clean > /dev/null; fi
	@echo "$(GREEN) objects cleaned$(RESET)"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(GREEN) $(NAME) removed$(RESET)"

re: fclean all

.PHONY: all clean fclean re init_progress