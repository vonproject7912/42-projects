/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokhadra <mokhadra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 14:37:23 by mokhadra          #+#    #+#             */
/*   Updated: 2026/01/11 10:39:35 by mokhadra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <limits.h>
# include <stdarg.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);

int					ft_tolower(int c);
int					ft_toupper(int c);

size_t				ft_strlen(const char *s);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_strcmp(char *s1, char *s2);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strnstr(const char *haystack, const char *needle,
						size_t len);
char				*ft_strdup(const char *s);
size_t				ft_strlcpy(char *dest, const char *src, size_t size);
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				**ft_split(char *str, char set);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
size_t				ft_strlcat(char *dest, const char *src, size_t size);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strtrim(char const *s1, char const *set);

void				*ft_memset(void *ptr, int value, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				ft_bzero(void *s, size_t n);
void				*ft_calloc(size_t count, size_t size);

void				ft_putnbr_fd(int n, int fd);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putendl_fd(char *s, int fd);

int					ft_atoi(const char *str);
char				*ft_itoa(int nb);

t_list				*ft_lstnew(void *content);
void				ft_lstadd_front(t_list **lst, t_list *new);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
						void (*del)(void *));
int					ft_printf(const char *s, ...);
int					ft_putchar_printf(int c);
int					ft_putstr_printf(char *str);
int					ft_putnbr_printf(int nb);
int					ft_putnbr_u(unsigned int n);
int					ft_putnbr_hexa(unsigned long nb);
int					ft_putnbr_hexa_maj(unsigned long nb);
int					print_addr(void *addr);
int					ft_print_args(const char *s, va_list *args, int *i);
char				*get_next_line(int fd);
int					search_n(char *s);
char				*new_tab(char *s, int *n);
char				*ft_strjoin_g(char *s1, char *s2);
char				*ft_strdup_g(char *s1);
char				*extract_line_from_stash(char **stash);
size_t				ft_strlen_g(char *str);
char				*ft_substr_g(char *s, unsigned int start, size_t len);
void				find_line(char **stash, char *buf, char **tmp, int fd);

#endif
