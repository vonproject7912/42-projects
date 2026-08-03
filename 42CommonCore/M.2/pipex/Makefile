# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vonpr <vonpr@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/04/08 19:10:07 by vonpr             #+#    #+#              #
#    Updated: 2026/08/03 19:20:34 by vonpr            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OBJS		=	$(SRCS:.c=.o)
NAME		=	pipex
CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror -g
INCLUDES	=	-I.
   
SRCS = tools/errors.c \
		tools/ft_split.c \
		tools/utils.c \
		pipex_utils.c \
		pipex.c

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