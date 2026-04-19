/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vonpr <vonpr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 10:04:11 by vonpr             #+#    #+#             */
/*   Updated: 2026/04/19 16:47:39 by vonpr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_redir(t_type type)
{
	if (type == REDIR_IN || type == REDIR_OUT || type == REDIR_APPEND
		|| type == HEREDOC)
		return (1);
	else
		return (0);
}

int	parse_command(int *lst_ext, t_token **tokens, t_cmd *command)
{
	int		size;
	t_token	*current;

	size = 0;
	current = *tokens;
	while (current && current->type != PIPE)
	{
		if (current->type == WORD)
			size++;
		else if (is_redir(current->type))
			current = current->next;
		if (current)
			current = current->next;
	}
	command->argv = malloc(sizeof(char *) * (size + 1));
	if (!command->argv)
		return (1);
	// function that fill everything
	return (*lst_ext);
}

// t_cmd *append_redir(int lst_ext, t_cmd *commands)
// {
// }

t_cmd	*parse(int *lst_ext, t_token **tokens)
{
	t_cmd	*commands;
	t_cmd	*current_cmd;

	commands = NULL;
	while (*tokens != NULL)
	{
		current_cmd = new_cmd();
		if (!current_cmd)
			return (NULL);
		if (parse_command(lst_ext, tokens, current_cmd) == SYNTAX_ERROR)
		{
			// free function for tokens, new_cmd and commands
			return (NULL);
		}
		add_cmd(&commands, current_cmd);
		if (*tokens && (*tokens)->type == PIPE)
		{
			*tokens = (*tokens)->next;
			if (*tokens == NULL)
				return (printf("minishell: syntax error near unexpected token `|'\n"),
					*lst_ext = 2, NULL);
		}
	}
	// function that frees my tokens
	return (commands);
}
