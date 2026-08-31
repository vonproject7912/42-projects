NAME = libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror -I.

# List of source files
SRCS = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c \
       ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c \
       ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c \
       ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c \
       ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c \
       ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strcmp.c ft_strnstr.c \
       ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c \
       ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
       ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c \
        printf/ft_printf.c printf/printf_utilities.c printf/printf_utilities2.c \
        get_next_line/get_next_line.c get_next_line/get_next_line_utils.c \

# Automatically generate object file names
OBJS = $(SRCS:.c=.o)

# Rule to compile source files into object files
%.o: %.c libft.h
	$(CC) $(CFLAGS) -c $< -o $@

# Default target to build the static library
all: $(NAME)

# Create the static library from the object files
$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

# Clean object files
clean:
	rm -f $(OBJS)

# Clean object files and the library
fclean: clean
	rm -f $(NAME)

# Rebuild everything (fclean + all)
re: fclean all

