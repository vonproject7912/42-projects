/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vonpr <vonpr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 10:04:11 by vonpr             #+#    #+#             */
/*   Updated: 2026/04/17 08:55:03 by vonpr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// parse() — main loop, splits by PIPE, returns t_cmd *
// parse_command() — builds one t_cmd (argv + redirs), stops at PIPE
// append_redir() — handles redirection tokens

