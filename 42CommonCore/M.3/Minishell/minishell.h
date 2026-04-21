/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vonpr <vonpr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/11 16:20:16 by vonpr             #+#    #+#             */
/*   Updated: 2026/04/21 11:12:34 by vonpr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define SUCCESS 0
# define SYNTAX_ERROR 2
# define MALLOC_ERROR 1

typedef enum es_type
{
	WORD,
	PIPE,
	REDIR_IN,
	REDIR_OUT,
	REDIR_APPEND,
	HEREDOC,
}					t_type;

typedef struct s_token
{
	t_type			type;
	char			*value;
	int				quote;
	struct s_token	*next;
}					t_token;

typedef struct s_redir
{
	t_type			type;
	char			*file;
	s_redir			*next;
}					t_redir;

typedef struct s_cmd
{
	char			**argv;
	t_redir			*redirs;
	s_cmd			*next;
}					t_cmd;

// utils
int					ft_strlen(char *str);
void				ft_putstr(int fd, char *str);
char				*ft_strndup(char *str, int len);
char				*ft_strjoin(char *s1, char *s2);
char				*ft_strdup(char *str);

// lexer utils
int					quotes_checking(char *str);
int					is_operator(char c);
void				value_assign(int *i, char *str, t_token *token);

// token utils
t_token				*new_token(void);
void				add_token(t_token **lst, t_token *new);
t_token				*get_last_token(t_token *lst);
void				merge_last_token(t_token *my_tokens, char *new_str);
void				token_routine(int *i, int *adj, char *str,
						t_token **my_tokens);

// actual lexer
void				token_routine(int *i, int *adj, char *str,
						t_token **my_tokens);
void				handle_double_quote(int *i, int *adj, char *str,
						t_token **my_tokens);
void				handle_operators(int *i, int *adj, char *str,
						t_token **my_tokens);
void				handle_anything_else(int *i, int *adj, char *str,
						t_token **my_tokens);
t_token				*lexer(int *lst_ext, char *str);

#endif