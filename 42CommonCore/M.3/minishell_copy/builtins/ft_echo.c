/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vonpr <vonpr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 09:50:17 by vonpr             #+#    #+#             */
/*   Updated: 2026/05/01 13:48:43 by vonpr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// validates if an argument is a valid '-n' option.
static int	is_n_option(char *arg)
{
	int	i;

	// a valid option must start with - and be followed by n
	if (!arg || arg[0] != '-' || arg[1] != 'n')
		return (0); // '-n'
	i = 2; // skip the '-' and the 'n'
	// check if everything after is also a n
	while (arg[i] == 'n')
		i++;
	// if it's the end of the string it's a valid flag
	// otherwise there was another char so return 0
	return (arg[i] == '\0');
}

// the implementation of the echo builtin
// the echo builtin: prints arguments separated by spaces
int	ft_echo(t_cmd *cmd)
{
	int	i;
	int	newline;

	i = 1; // start at index 1 (index 0 is the word "echo" itself)
	newline = 1; // by default, echo prints a newline at the end
	// if there is a flag, print on the same line
	while (cmd->argv[i] && is_n_option(cmd->argv[i]))
	{
		newline = 0;
		i++;
	}
	// print the remaining arguments
	while (cmd->argv[i])
	{
		// print the current argument
		ft_putstr(1, cmd->argv[i]);
		// if there is another argument 
		// after print a space
		if (cmd->argv[i + 1])
			ft_putstr(1, " ");
		i++;
	}
	// if there are no valid -n flag 
	if (newline) // print a newline
		ft_putstr(1, "\n");
	return (0);
}
