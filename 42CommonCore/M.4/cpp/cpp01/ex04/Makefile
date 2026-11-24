# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vonpr <vonpr@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/11/23 00:03:42 by vonpr             #+#    #+#              #
#    Updated: 2026/11/24 15:33:19 by vonpr            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME     = replace
CXX      = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS     = main.cpp
OBJS     = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)
	@echo "Compiled !"

%.o: %.cpp $(HEADERS)
	@$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re