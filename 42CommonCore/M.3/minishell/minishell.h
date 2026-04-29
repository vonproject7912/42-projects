/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vonpr <vonpr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 11:16:10 by vonpr             #+#    #+#             */
/*   Updated: 2026/04/29 18:06:12 by vonpr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <errno.h>
# include <fcntl.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <unistd.h>

extern volatile sig_atomic_t	g_signal;

typedef enum es_type
{
	WORD,
	PIPE,
	REDIR_IN,
	REDIR_OUT,
	REDIR_APPEND,
	HEREDOC,
}								t_type;

typedef struct s_token
{
	t_type						type;
	char						*value;
	int							quote;
	struct s_token				*next;
}								t_token;

typedef struct s_redir
{
	t_type						type;
	char						*file;
	int							quote;
	int							heredoc_fd;
	struct s_redir				*next;
}								t_redir;

typedef struct s_cmd
{
	char						**argv;
	int							*quotes;
	t_redir						*redirs;
	struct s_cmd				*next;
}								t_cmd;

typedef struct s_shell
{
	char						**envp;
	int							last_exit;
	int							should_exit;
}								t_shell;

// utils
int								ft_strlen(char *str);
void							ft_putstr(int fd, char *str);
char							*ft_strndup(char *str, int len);
char							*ft_strjoin(char *s1, char *s2);
char							*ft_strdup(char *str);
int								ft_strcmp(char *s1, char *s2);
int								ft_strncmp(char *s1, char *s2, int n);
char							*ft_strchr(char *str, int c);
char							*ft_itoa(int n);

// lexer utils
int								quotes_checking(char *str);
int								is_operator(char c);
void							value_assign(int *i, char *str, t_token *token);

// token utils
t_token							*new_token(void);
void							add_token(t_token **lst, t_token *new);
t_token							*get_last_token(t_token *lst);
void							merge_last_token(t_token *my_tokens,
									char *new_str);
void							token_routine(int *i, int *adj, char *str,
									t_token **my_tokens);

// actual lexer
void							handle_single_quote(int *i, int *adj, char *str,
									t_token **my_tokens);
void							handle_double_quote(int *i, int *adj, char *str,
									t_token **my_tokens);
void							handle_operators(int *i, int *adj, char *str,
									t_token **my_tokens);
void							handle_anything_else(int *i, int *adj,
									char *str, t_token **my_tokens);
t_token							*lexer(t_shell *shell, char *str);

// syntax check
void							pipe_err(void);
void							redir_err(void);
int								last_token_check(t_token *current);
int								syntax_check(t_token *tokens);

// parsing utils
t_cmd							*new_cmd(void);
void							add_cmd(t_cmd **lst, t_cmd *new);
void							malloc_err(t_shell *shell);

// parsing free utils
void							free_tokens(t_token **tokens);
void							free_redir(t_cmd **commands);
void							free_commands(t_cmd **commands);

// redirections
t_redir							*new_redir(void);
void							add_redir(t_redir **lst, t_redir *new);
int								append_redir(t_token **tokens, t_cmd *command);

// actual parsing
int								add_str(t_token **tokens, t_cmd *command);
int								cmd_fill(t_token **tokens, t_cmd *command);
t_cmd							*append_cmd(t_shell *shell, t_token **tokens,
									t_cmd *commands);
t_cmd							*parse(t_shell *shell, t_token **tokens);

// expand utils
int								is_var_start(char c);
int								is_var_char(char c);
char							*append_part(char *result, char *part);

// expand
char							*get_env_value(char *key, char **env);
char							*expand_var(int *i, char *str, char **env,
									t_shell *shell);
int								expand_str(char **str, int quote, char **env,
									t_shell *shell);
int								expand_cmd(t_cmd *commands, char **env,
									t_shell *shell);

// shell loop
int								shell_loop(char **envp);

// env
char							**env_dup(char **envp);
void							free_env(char **envp);
char							*env_get(char **envp, char *key);
int								env_set(t_shell *shell, char *entry);
int								env_unset(t_shell *shell, char *key);

// builtins
int								is_builtin(char *cmd);
int								is_parent_builtin(char *cmd);
int								run_builtin(t_shell *shell, t_cmd *cmd);
int								ft_echo(t_cmd *cmd);
int								ft_cd(t_shell *shell, t_cmd *cmd);
int								ft_pwd(void);
int								ft_export(t_shell *shell, t_cmd *cmd);
int								ft_unset(t_shell *shell, t_cmd *cmd);
int								ft_env(t_shell *shell, t_cmd *cmd);
int								ft_exit(t_shell *shell, t_cmd *cmd);

// exec
int								run_commands(t_cmd *commands, t_shell *shell);
int								open_heredoc(char *delimiter);

// signals
void							setup_prompt_signals(void);
void							setup_parent_exec_signals(void);
void							setup_child_exec_signals(void);

#endif