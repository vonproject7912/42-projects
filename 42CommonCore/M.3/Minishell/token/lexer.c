/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vonpr <vonpr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/11 16:28:36 by vonpr             #+#    #+#             */
/*   Updated: 2026/04/15 10:02:31 by vonpr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	handle_single_quote(int *i, char *str, t_token **my_tokens)
{
	int		start;
	t_token	*token;

	token = new_token();
	token->quote = 1;
	token->type = WORD;
	(*i)++;
	start = *i;
	while (str[*i] && str[*i] != '\'')
		(*i)++;
	token->value = ft_strndup(str + start, *i - start);
	(*i)++;
	add_token(my_tokens, token);
}

void	handle_double_quote(int *i, char *str, t_token **my_tokens)
{
	int		start;
	t_token	*token;

	token = new_token();
	token->quote = 2;
	token->type = WORD;
	(*i)++;
	start = *i;
	while (str[*i] && str[*i] != '"')
		(*i)++;
	token->value = ft_strndup(str + start, *i - start);
	(*i)++;
	add_token(my_tokens, token);
}

void	handle_anything_else(int *i, char *str, t_token **my_tokens)
{
	int		start;
	t_token	*token;

	token = new_token();
	token->quote = 0;
	token->type = WORD;
	start = *i;
	while (str[*i] && str[*i] != ' ' && str[*i] != '\t'
		&& !is_operator(str[*i]))
		(*i)++;
	token->value = ft_strndup(str + start, *i - start);
	add_token(my_tokens, token);
}

void	handle_operators(int *i, char *str, t_token **my_tokens)
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

t_token	*lexer(char *str, int *lst_ext)
{
	int		i;
	t_token	*my_tokens;

	i = 0;
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
			handle_single_quote(&i, str, &my_tokens);
		else if (str[i] == '"')
			handle_double_quote(&i, str, &my_tokens);
		else if (is_operator(str[i]))
			handle_operators(&i, str, &my_tokens);
		else
			handle_anything_else(&i, str, &my_tokens);
	}
	return (my_tokens);
}
