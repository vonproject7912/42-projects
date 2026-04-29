/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vonpr <vonpr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 11:08:44 by vonpr             #+#    #+#             */
/*   Updated: 2026/04/29 15:37:34 by vonpr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// create a new token / node
t_token	*new_token(void)
{
	t_token	*token;

	token = malloc(sizeof(t_token));
	if (!token)
		return (NULL);
	token->quote = 0;
	token->next = NULL;
	token->value = NULL;
	return (token);
}

// add the token to the linked list
void	add_token(t_token **lst, t_token *new)
{
	t_token	*current;

	if (!*lst)
	{
		*lst = new;
		return ;
	}
	current = *lst;
	while (current->next)
		current = current->next;
	current->next = new;
}

// get the last token in the linked list
t_token	*get_last_token(t_token *lst)
{
	t_token	*last_token;

	last_token = lst;
	while (last_token->next != NULL)
		last_token = last_token->next;
	return (last_token);
}

// merge the rest of a word in the last token 
// (ex: "hel"lo we get hello)
void	merge_last_token(t_token *my_tokens, char *new_str)
{
	char	*old_value;
	t_token	*last_token;

	last_token = get_last_token(my_tokens);
	old_value = last_token->value;
	if (!old_value)
		last_token->value = new_str;
	else
	{
		last_token->value = ft_strjoin(old_value, new_str);
		free(old_value);
		free(new_str);
	}
}

// the "Traffic Controller": decides how to handle the current character
void	token_routine(int *i, int *adj, char *str, t_token **my_tokens)
{
	// skip spaces and set adj to 0
	if (str[*i] == ' ' || str[*i] == '\t')
	{
		*adj = 0;
		(*i)++;
	}
	else if (str[*i] == '\'')
		handle_single_quote(i, adj, str, my_tokens);
	else if (str[*i] == '"')
		handle_double_quote(i, adj, str, my_tokens);
	else if (is_operator(str[*i]))
		handle_operators(i, adj, str, my_tokens);
	else
		handle_anything_else(i, adj, str, my_tokens);
}
