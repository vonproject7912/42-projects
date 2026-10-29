# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mosriji <mosriji@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/10/29 15:46:37 by mosriji           #+#    #+#              #
#    Updated: 2026/10/29 15:46:39 by mosriji          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = megaphone
CXX     = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS    = megaphone.cpp
OBJS    = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re