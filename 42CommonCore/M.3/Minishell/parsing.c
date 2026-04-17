/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vonpr <vonpr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 10:04:11 by vonpr             #+#    #+#             */
/*   Updated: 2026/04/16 12:36:04 by vonpr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* splits commands by PIPE into separate t_cmd nodes
builds argv[] for each command
attaches t_redir linked list to each command
catches syntax errors (| with no command, > with no filename etc.)
returns the t_cmd linked list ready for the expander then executor 

Because the lexer's only job is to split and label — it doesn't know yet if a word is 
a command, an argument, or a filename. That context comes from the parser, which 
groups tokens into commands by splitting on PIPE and assigns words to argv.
*/

#include "minishell.h"

void split_command(t_token *my_tokens)
{
    // split commands by pipe into a cmd linked list
    // progressievlly also free my_token
    // return the cmd linked list
}

void build_argv(t_cmd *commands)
{
    // create my own argv and fill it with the commands
    // free my linked list of commands
    // return my argv
}

void parsing(int lst_ext, t_token *my_tokens)
{
    // call for my split_command function
    // call for my build_arg function
    // return the argv 
    // (for the expand then to the exec)
}

void ??(t_token **tokens)
{
    t_cmd *commands;

    commands = malloc(sizeof(t_cmd));
    if (!commands)
        return (NULL);
    
}

// split my tokens into a cmd linked list by pipes
// fill each commands with their argv and redirections

int parsing(int *lst_ext, t_token ** tokens)
{
    
}
