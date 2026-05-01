/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vonpr <vonpr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 09:51:02 by vonpr             #+#    #+#             */
/*   Updated: 2026/05/01 13:20:20 by vonpr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// the implementation of the unset builtin
int	ft_unset(t_shell *shell, t_cmd *cmd)
{
	int	i;
	int	status;

	i = 1; // start at 1
	// (index 0 is "unset" itself)
	status = 0; // return status of the replacement
	// lopp throught every argument provided to unset
	while (cmd->argv[i])
	{
		// variable name can't have a '=' to it or start with a number
		if (!is_valid_identifier(cmd->argv[i]))
		{
			ft_putstr(2, "minishell: unset: not a valid identifier\n");
			status = 1; // mark that at least one argument failed
		}
		// otherwise replace the variable
		else if (env_unset(shell, cmd->argv[i]))
			status = 1;
		i++;
	}
	// return the status
	return (status);
}
