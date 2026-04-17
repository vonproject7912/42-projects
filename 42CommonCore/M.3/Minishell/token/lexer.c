/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vonpr <vonpr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/11 16:28:36 by vonpr             #+#    #+#             */
/*   Updated: 2026/04/17 12:05:53 by vonpr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	handle_single_quote(int *i, int *adj, char *str, t_token **my_tokens)
{
	int		start;
	char	*new_str;
	t_token	*token;
	t_token	*last_token;

	(*i)++;
	start = *i;
	while (str[*i] && str[*i] != '\'')
		(*i)++;
	new_str = ft_strndup(str + start, *i - start);
	(*i)++;
	if (*adj == 1)
		merge_last_token(*my_tokens, new_str);
	else
	{
		token = new_token();
		token->quote = 1;
		token->type = WORD;
		token->value = new_str;
		add_token(my_tokens, token);
	}
	*adj = 1; //wtf
}

void	handle_double_quote(int *i, int adjacent, char *str, t_token **my_tokens)
{
	int		start;
	char	*new_str;
	t_token	*token;
	t_token	*last_token;

	(*i)++;
	start = *i;
	while (str[*i] && str[*i] != '\'')
		(*i)++;
	new_str = ft_strndup(str + start, *i - start);
	(*i)++;
	if (*adj == 1)
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

void	handle_anything_else(int *i, int adjacent, char *str, t_token **my_tokens)
{
	int		start;
	char	*new_str;
	t_token	*token;
	t_token	*last_token;

	(*i)++;
	start = *i;
	while (str[*i] && str[*i] != '\'')
		(*i)++;
	new_str = ft_strndup(str + start, *i - start);
	(*i)++;
	if (*adj == 1)
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

void	handle_operators(int *i, int adjacent, char *str, t_token **my_tokens)
{
	t_token	*token;

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
	token->value = NULL;
	(*i)++;
	if (token->type == REDIR_APPEND || token->type == HEREDOC)
		(*i)++;
	add_token(my_tokens, token);
}

t_token	*lexer(int *lst_ext, char *str)
{
	int		i;
	int		adjacent;
	t_token	*my_tokens;

	i = 0;
	adjacent = 0;
	my_tokens = NULL;
	if (quotes_checking(str))
		return (err(lst_ext, "minishell: syntax error: unclosed quote"), NULL);
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	if (!str[i])
		return (NULL);
	while (str[i])
	{
		if (str[i] == ' ' || str[i] == '\t')
			i++;
		else if (str[i] == '\'')
			handle_single_quote(&i, &adjacent, str, &my_tokens);
		else if (str[i] == '"')
			handle_double_quote(&i, &adjacent, str, &my_tokens);
		else if (is_operator(str[i]))
			handle_operators(&i, &adjacent, str, &my_tokens);
		else
			handle_anything_else(&i, &adjacent, str, &my_tokens);
	}
	return (my_tokens);
}

#include "minishell.h"
#include <stdio.h>

void run_test(char *input)
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