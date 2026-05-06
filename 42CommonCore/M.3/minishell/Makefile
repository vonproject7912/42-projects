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
                expand/expand.c \
                expand/expand_utils.c \
                exec/exec_one.c \
                exec/exec_two.c \
                exec/exec_three.c \
                exec/heredoc.c \
                exec/signals.c \
                exec/env.c \
                exec/env_utils.c \
                builtins/ft_echo.c \
                builtins/ft_cd.c \
                builtins/ft_pwd.c \
                builtins/ft_export_utils.c \
                builtins/ft_export.c \
                builtins/ft_unset.c \
                builtins/ft_env.c \
                builtins/ft_exit.c \
                shell_utils.c \
                shell_loop.c \
                utils_one.c \
                utils_two.c \
                main.c

LDFLAGS     = -lreadline

OBJS        = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@echo "$(G)Linking objects...$(W)"
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LDFLAGS)
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