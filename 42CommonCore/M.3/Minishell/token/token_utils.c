/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vonpr <vonpr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 12:06:10 by vonpr             #+#    #+#             */
/*   Updated: 2026/04/17 16:05:14 by vonpr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

t_token	*get_last_token(t_token *lst)
{
	t_token	*last_token;

	last_token = lst;
	while (last_token->next != NULL)
		last_token = last_token->next;
	return (last_token);
}

void	merge_last_token(t_token *my_tokens, char *new_str)
{
	char	*old_value;
	t_token	*last_token;

	last_token = get_last_token(my_tokens);
	old_value = last_token->value;
	last_token->value = ft_strjoin(old_value, new_str);
	if (!old_value)
		last_token->value = new_str;
	else
	{
		last_token->value = ft_strjoin(old_value, new_str);
		free(old_value);
		free(new_str);
	}
}

void	value_assign(int *i, char *str, t_token *token)
{
	if (str[*i] == '|')
		token->value = ft_strndup("|", 1);
	else if (str[*i] == '>' && str[*i + 1] == '>')
		token->value = ft_strndup(">>", 2);
	else if (str[*i] == '<' && str[*i + 1] == '<')
		token->value = ft_strndup("<<", 2);
	else if (str[*i] == '<')
		token->value = ft_strndup("<", 1);
	else if (str[*i] == '>')
		token->value = ft_strndup(">", 1);
	if (token->type == REDIR_APPEND || token->type == HEREDOC)
		*i += 2;
	else
		*i += 1;
}
