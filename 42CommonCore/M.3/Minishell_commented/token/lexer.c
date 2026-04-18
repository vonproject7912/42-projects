/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vonpr <vonpr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/11 16:28:36 by vonpr             #+#    #+#             */
/*   Updated: 2026/04/18 16:07:24 by vonpr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// process the content inside a single quote
void	handle_single_quote(int *i, int *adj, char *str, t_token **my_tokens)
{
	int		start;
	char	*new_str;
	t_token	*token;

	(*i)++; // we pass the opening quote
	start = *i; // save the start inside the quote
	while (str[*i] && str[*i] != '\'')
		(*i)++; // go to the end of the quote as a delimiter
	new_str = ft_strndup(str + start, *i - start); // extract with the delimiter 
	if (str[*i] == '\'')
		(*i)++; // skip the ending quote
	if (*my_tokens && *adj == 1) // if adjacent to a previous word, merge them
		merge_last_token(*my_tokens, new_str);
	else // otherwise create and fill a new token
	{
		token = new_token();
		token->quote = 1; // set single quotes to 1
		token->type = WORD;
		token->value = new_str;
		add_token(my_tokens, token);
	}
	*adj = 1; // set the mark to 1 
	// and change it to 0 if it encounter a space
}

// same process but with double quotes
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
		token->quote = 2; // set double quotes to 2
		token->type = WORD;
		token->value = new_str;
		add_token(my_tokens, token);
	}
	*adj = 1;
}

// handle standard words until an operator or space is hit
void	handle_anything_else(int *i, int *adj, char *str, t_token **my_tokens)
{
	int		start;
	char	*new_str;
	t_token	*token;

	start = *i; // save the start
	while (str[*i] && str[*i] != ' ' && str[*i] != '\t' && str[*i] != '\''
		&& str[*i] != '\"' && !is_operator(str[*i]))
		(*i)++; // keep moving until we hit a delimiter
	new_str = ft_strndup(str + start, *i - start);
	if (*my_tokens && *adj == 1 && get_last_token(*my_tokens)->type == WORD)
		merge_last_token(*my_tokens, new_str); // merge if it's the continuation of a word
	else // otherwise same as before, create a new token
	{
		token = new_token();
		token->quote = 0;
		token->type = WORD;
		token->value = new_str;
		add_token(my_tokens, token);
	}
	*adj = 1;
}

// identifies shell operators: |, <, >, << and >>
void	handle_operators(int *i, int *adj, char *str, t_token **my_tokens)
{
	t_token	*token;

	*adj = 0; // operators are never "adjacent" to words for merging
	token = new_token(); // create a new token
	token->quote = 0; // no quotes
	// identify the type of the operator
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
	value_assign(i, str, token); // assigne the actual value of the operator
	add_token(my_tokens, token); // add the token to the linked list
}

// my main lexer function: converts the input string into a list of tokens
t_token	*lexer(int *lst_ext, char *str)
{
	int		i;
	int		adj;
	t_token	*my_tokens;

	i = 0;
	adj = 0;
	my_tokens = NULL;
	// first check: if there are any unclosed quotes
	if (quotes_checking(str))
	{
		ft_putstr(2, "minishell: syntax error: unclosed quote\n");
		if (lst_ext)
			*lst_ext = 2; // exit status for syntqx error
		return (NULL);
	}
	// skip spaces
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	if (!str[i]) // check for empty input
		return (NULL);
	// loop over the string building my token linked list
	while (str[i])
		token_routine(&i, &adj, str, &my_tokens);
	return (my_tokens);
}
