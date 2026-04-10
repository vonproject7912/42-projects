# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vonpr <vonpr@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/04/07 18:40:53 by vonpr             #+#    #+#              #
#    Updated: 2026/04/10 16:01:36 by vonpr            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OBJS		=	$(SRCS:.c=.o)
NAME		=	push_swap
CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror -g
INCLUDES	=	-I.

SRCS		= operations/push.c \
				operations/reverse.c \
				operations/rotate.c \
				operations/swap.c \
				parsing/parsing_utils.c \
				parsing/parsing.c \
				sorting/checking_moving.c \
				sorting/specific_cases.c \
				stack/put_index.c \
				stack/stack_fill.c \
				tools/errors.c \
				tools/ft_split.c \
				tools/long_range.c \
				radix.c \
				main.c

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) -o $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re