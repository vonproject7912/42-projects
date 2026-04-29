NAME        = minishell
CC          = cc
CFLAGS      = -Wall -Wextra -Werror -I.
RM          = rm -f

G           = \033[0;32m
DG          = \033[1;32m
R           = \033[0;31m
W           = \033[0m

SRCS        =   token/lexer_utils.c \
                token/lexer.c \
                token/token_utils.c \
                parsing/free_parsing.c \
                parsing/parsing_utils.c \
                parsing/parsing.c \
                parsing/redirections.c \
                parsing/syntax_check.c \
                utils.c

OBJS        = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@echo "$(G)Linking objects...$(W)"
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "$(DG)>> $(NAME) ready.$(W)"

%.o: %.c
	@echo "$(G)Compiling $<...$(W)"
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJS)
	@echo "$(R)Objects removed.$(W)"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(R)Binary removed.$(W)"

re: fclean all

.PHONY: all clean fclean re