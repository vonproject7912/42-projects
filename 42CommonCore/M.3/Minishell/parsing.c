/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vonpr <vonpr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 10:04:11 by vonpr             #+#    #+#             */
/*   Updated: 2026/04/19 12:44:19 by vonpr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// parse() — main loop, splits by PIPE, returns t_cmd *
// parse_command() — builds one t_cmd (argv + redirs), stops at PIPE
// append_redir() — handles redirection tokens

// int parse_command(int lst_ext, t_cmd *command)
// {
//     char **argv; // create an argv
//     int size_argv; // my counter
//     t_token *current; // my reader

//     size_argv = 0;
//     current = *tokens;
//     // get the size of my argv
//     while (*token->type != PIPE && *token->next != NULL)
//     {
//         size_argv += 1;
//         current = current->next;
//     } // to allocate the argv
//     argv = malloc(sizeof(char *) * (size_argv + 1));
//     if (!argv)
//         return (NULL);
//     commands->argv = argv;
// }

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
