/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vonpr <vonpr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 10:04:11 by vonpr             #+#    #+#             */
/*   Updated: 2026/04/18 16:47:06 by vonpr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// parse() — main loop, splits by PIPE, returns t_cmd *
// parse_command() — builds one t_cmd (argv + redirs), stops at PIPE
// append_redir() — handles redirection tokens

t_cmd *parse_command(int lst_ext, t_cmd *commands)
{
    
}

t_cmd *append_redir(t_cmd *commands)
{
    
}

t_cmd *parse(int lst_ext, t_token *tokens)
{
    
}
