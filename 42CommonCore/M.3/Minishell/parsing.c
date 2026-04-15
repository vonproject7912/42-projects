/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vonpr <vonpr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 10:04:11 by vonpr             #+#    #+#             */
/*   Updated: 2026/04/15 12:48:21 by vonpr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
/*
Parsing also:
- splits commands by `PIPE` into separate `t_cmd` nodes
- builds `argv[]` for each command
- attaches `t_redir` linked list to each command
- catches syntax errors (`|` with no command, `>` with no filename etc.)
- returns the `t_cmd` linked list ready for the expander then executor
*/

void split_command(t_token *my_tokens)
{
    // actually spliting things into an array with pipes
    // free my "my_tokens"
    // build and loop over each command and put them into a cmd node
    // return the node
}

void build_argv(t_cmd *commands)
{
    // create my own argv and fill it with the commands
    // free my linked list of commands
    // return my argv
}

void parsing(int lst_ext, t_token *my_tokens)
{
    // function for the commands building
    // call for my split command function
    // build my actual argv
    // return the argv to the expand 
    // then expand to the exec
}