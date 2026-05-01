/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vonpr <vonpr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 09:50:28 by vonpr             #+#    #+#             */
/*   Updated: 2026/05/01 13:26:29 by vonpr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// the implementation of the env builtin
// the env builtin: displays all environment variables
int	ft_env(t_shell *shell, t_cmd *cmd)
{
	int	i;

	if (cmd->argv[1])
	{
		// doesn't accept any other argument other then env
		ft_putstr(2, "minishell: env: no options or arguments supported\n");
		return (1);
	}
	i = 0;
	// loop through our 'custom' env
	while (shell->envp && shell->envp[i])
	{
		// only print variables with a '=' sign
		if (ft_strchr(shell->envp[i], '='))
		{
			// print "KEY=VALUE"
			ft_putstr(1, shell->envp[i]);
			// print a newline
			ft_putstr(1, "\n");
		}
		i++;
	}
	return (0);
}
