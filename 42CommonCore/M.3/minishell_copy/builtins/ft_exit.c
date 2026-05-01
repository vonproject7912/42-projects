/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vonpr <vonpr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 09:50:36 by vonpr             #+#    #+#             */
/*   Updated: 2026/05/01 13:39:45 by vonpr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// check if the string provided is a valid number
static int	is_numeric(char *str)
{
	int	i;

	i = 0;
	// allow a single leading plus or minus sign
	if (str[i] == '+' || str[i] == '-')
		i++;
	// no digits fail
	if (!str[i])
		return (0);
	// loop throught the remaining characters
	while (str[i])
	{
		// ensure that they are digits
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

// small atoi
static int	ft_atoi_exit(char *str)
{
	int					i;
	int					sign;
	unsigned long long	value;

	i = 0;
	sign = 1;
	value = 0;
	// handles the sign
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	// loop over 
	while (str[i]) // regular atoi
		value = value * 10 + (str[i++] - '0');
	/* Logic: Exit codes in Linux are 8-bit (0-255)
     * The '& 255' (bitwise AND) performs a modulo 256
     * Example: 'exit 257' actually returns 1 */
	return ((int)((value * sign) & 255));
}

// the implementation of the shell builtin
// it handles shell termination and exit codes
int	ft_exit(t_shell *shell, t_cmd *cmd)
{
	// print an actual exit
	ft_putstr(1, "exit\n");
	// case 1: the argument isn't a number
	if (cmd->argv[1] && !is_numeric(cmd->argv[1]))
	{
		ft_putstr(2, "minishell: exit: numeric argument required\n");
		shell->last_exit = 2; // error code 2 for syntax error
	}
	// case 2: to many arguments
	else if (cmd->argv[1] && cmd->argv[2])
	{
		ft_putstr(2, "minishell: exit: too many arguments\n");
		return (1); // shell stays open if there too many arguments
	}
	// case 3: valid single numeric argument
	else if (cmd->argv[1]) // print the last exit 
		shell->last_exit = ft_atoi_exit(cmd->argv[1]);
	// set the flag to 1 for shell_loop to stop running
	shell->should_exit = 1;
	return (shell->last_exit);
}
