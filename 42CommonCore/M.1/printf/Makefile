# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vonpr <vonpr@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/03/30 01:33:46 by vonpr             #+#    #+#              #
#    Updated: 2026/04/10 15:29:21 by vonpr            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_printf.c\
		ft_print_char.c\ 
		ft_print_str.c\
		ft_print_putnbr.c\
		ft_print_adress.c\
		ft_print_positif_putnbr.c\
		ft_print_hexa.c\
		ft_print_up_hexa.c\
		ft_hexa_ptr.c\

OBJS = $(SRCS:.c=.o)

NAME = libftprintf.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

INCLUDES = -I.

all: $(NAME)

$(NAME): $(OBJS)
	@ar rc $(NAME) $(OBJS)

%.o: %.c
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re