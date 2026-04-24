/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vonpr <vonpr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 17:36:25 by vonpr             #+#    #+#             */
/*   Updated: 2026/04/23 13:13:46 by vonpr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// — walks env array, finds KEY=value, returns value part
get_env_value(char *key, char **env)
{
    
}

// — finds $VAR or $?, looks up value, returns expanded string
expand_var(char *str, char **env, int last_exit)
{
    
}

// — expands a single string based on quote type, returns new string
int expand_str(char *str, int quote, char **env)
{
    
}

// — walks every command, calls expanders on each argv[i] and redir->file
int expand_cmd(t_cmd *commands, char **env, int last_exit) 
{
    t_cmd *current;

    current = commands;
    while (current)
    {
        if (expand_str(current->argv, current->quotes, env))
            return (malloc_err(last_exit), 1);
        else if (expand_str(current->redir->file, current->quotes, env))
            return (malloc_err(last_exit), 1);
        current  = current->next;
    }
    return (0);
}
