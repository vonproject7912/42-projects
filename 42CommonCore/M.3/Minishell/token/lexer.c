/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vonpr <vonpr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/11 16:28:36 by vonpr             #+#    #+#             */
/*   Updated: 2026/04/17 16:59:19 by vonpr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	handle_single_quote(int *i, int *adj, char *str, t_token **my_tokens)
{
	int		start;
	char	*new_str;
	t_token	*token;

	(*i)++;
	start = *i;
	while (str[*i] && str[*i] != '\'')
		(*i)++;
	new_str = ft_strndup(str + start, *i - start);
	if (str[*i] == '\'')
		(*i)++;
	if (*my_tokens && *adj == 1)
		merge_last_token(*my_tokens, new_str);
	else
	{
		token = new_token();
		token->quote = 1;
		token->type = WORD;
		token->value = new_str;
		add_token(my_tokens, token);
	}
	*adj = 1;
}

void	handle_double_quote(int *i, int *adj, char *str, t_token **my_tokens)
{
	int		start;
	char	*new_str;
	t_token	*token;

	(*i)++;
	start = *i;
	while (str[*i] && str[*i] != '"')
		(*i)++;
	new_str = ft_strndup(str + start, *i - start);
	if (str[*i] == '"')
		(*i)++;
	if (*my_tokens && *adj == 1)
		merge_last_token(*my_tokens, new_str);
	else
	{
		token = new_token();
		token->quote = 2;
		token->type = WORD;
		token->value = new_str;
		add_token(my_tokens, token);
	}
	*adj = 1;
}

void	handle_anything_else(int *i, int *adj, char *str, t_token **my_tokens)
{
	int		start;
	char	*new_str;
	t_token	*token;

	start = *i;
	while (str[*i] && str[*i] != ' ' && str[*i] != '\t' && str[*i] != '\''
		&& str[*i] != '\"' && !is_operator(str[*i]))
		(*i)++;
	new_str = ft_strndup(str + start, *i - start);
	if (*my_tokens && *adj == 1 && get_last_token(*my_tokens)->type == WORD)
		merge_last_token(*my_tokens, new_str);
	else
	{
		token = new_token();
		token->quote = 0;
		token->type = WORD;
		token->value = new_str;
		add_token(my_tokens, token);
	}
	*adj = 1;
}

void	handle_operators(int *i, int *adj, char *str, t_token **my_tokens)
{
	t_token	*token;

	*adj = 0;
	token = new_token();
	token->quote = 0;
	if (str[*i] == '|')
		token->type = PIPE;
	else if (str[*i] == '>' && str[*i + 1] == '>')
		token->type = REDIR_APPEND;
	else if (str[*i] == '<' && str[*i + 1] == '<')
		token->type = HEREDOC;
	else if (str[*i] == '<')
		token->type = REDIR_IN;
	else if (str[*i] == '>' && str[*i + 1] != '>')
		token->type = REDIR_OUT;
	value_assign(i, str, token);
	add_token(my_tokens, token);
}

t_token	*lexer(int *lst_ext, char *str)
{
	int		i;
	int		adj;
	t_token	*my_tokens;

	i = 0;
	adj = 0;
	my_tokens = NULL;
	if (quotes_checking(str))
	{
		ft_putstr(2, "minishell: syntax error: unclosed quote\n");
		if (lst_ext)
			*lst_ext = 2;
		return (NULL);
	}
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	if (!str[i])
		return (NULL);
	while (str[i])
		token_routine(&i, &adj, str, &my_tokens);
	return (my_tokens);
}

*void run_test(char *input)
{
    t_token *tokens;
    t_token *tmp;
    int     i = 0;

    printf("\033[1;34mTesting: \033[0m[%s]\n", input);
    printf("--------------------------------------\n");
    
    // Assuming your lexer takes (NULL/ptr, string)
    tokens = lexer(0, input); 
    
    tmp = tokens;
    while (tmp)
    {
        printf("Token %d: type=%d | value='%s'\n", i++, tmp->type, tmp->value);
        tmp = tmp->next;
    }
    printf("\n");
    // Add your list freeing function here to avoid leaks!
    // free_lexer(tokens); 
}

int main(void)
{
    char *tests[] = {
        /* 1. Basic Operators */
        "ls -la | grep .c",
        "ls>fileout>>append<filein",
        
        /* 2. Complex Quotes (The "hel"lo case) */
        "\"hel\"lo",                // Should be 1 token: hello
        "echo \"  spaced  \"",      // Should be 2 tokens: echo |   spaced  
        "''\"\"' '",                // Should be 1 token: (space)
        "ls' -la'",                 // Should be 1 token: ls -la
        
        /* 3. Metacharacters inside quotes */
        "echo \"| >> <\"",          // Should be 2 tokens: echo | | >> <
        "grep '|' file",            // Should be 3 tokens: grep | | | file
        
        /* 4. Environment Variables (Lexer shouldn't expand, just keep as WORD) */
        "echo $USER",
        "echo \"$USER\"",
        "echo '$USER'",             // Difference is handled in expansion, not lexer
        
        /* 5. Edge cases / Syntax errors */
        "|||",                      // 3 PIPE tokens
        ">>>",                      // REDIR_APPEND + REDIR_OUT (or syntax error later)
        "   ",                      // Should return NULL or empty
        "\"unclosed quote",         // Your choice: error or literal
        NULL
    };

    for (int i = 0; tests[i]; i++)
        run_test(tests[i]);

    return (0);
}
