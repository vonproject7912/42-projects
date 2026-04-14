/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vonpr <vonpr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/11 16:28:36 by vonpr             #+#    #+#             */
/*   Updated: 2026/04/14 10:21:52 by vonpr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// typedef enum es_type
// {
// 	WORD,
// 	PIPE,
// 	REDIR_IN,
// 	REDIR_OUT,
// 	REDIR_APPEND,
// 	HEREDOC,
// }					t_type;

// typedef struct s_token
// {
// 	t_type			type;
// 	char			*value;
// 	int				quote;
// 	struct s_token	*next;
// }					t_token;

void handle_single_quote(int *i, char *str, t_token	**my_tokens)
{
	int start;
	t_token *token;

	token = new_token();
	token->quote = 1;
	token->type = WORD;
	(*i)++; // pass the '
	start = *i;
	while(str[*i] && str[*i] != '\'')
		(*i)++;
	token->value = ft_strndup(str + start, *i - start);
	(*i)++; // pass the end '
	add_token(my_tokens, token);
}

t_token	*lexer(char *str, int *lst_ext)
{
	int		i;
	t_token	*my_tokens;

	i = 0;
	my_tokens = NULL;  // init my linked list
	if (quotes_checking(str)) // check for unclosed quotes
		return (err(lst_ext, "minishell: syntax error: unclosed quote"), NULL);
	while (str[i] == ' ' || str[i] == '\t')
		i++; // skip space
	if (!str[i])
	    return (NULL); // early return for empty input
	while (str[i]) // loop and fill my tokens
	{
	    if (str[i] == '\'')
	        handle_single_quote(&i, str, &my_tokens);
	    else if (str[i] == '"')
	        // function for double quotes
	    else if (str[i] == ' ' || str[i] == '\t')
	        i++;
	    else if (is_operator(str[i]))
	        // function handle_operators
	    else
	        // function for regular words until space or operator
	}
	return (my_tokens);
}

void handle_double_quote()
{
	
}

void handle_operators()
{
	
}

void handle_anything_else()
{
	
}
