/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vonpr <vonpr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 09:50:07 by vonpr             #+#    #+#             */
/*   Updated: 2026/05/01 13:12:23 by vonpr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// count the number of arguments
static int	argv_count(char **argv)
{
	int	count;

	count = 0;
	while (argv[count])
		count++;
	return (count);
}

// the implementation of the 'cd' command
int	ft_cd(t_shell *shell, t_cmd *cmd)
{
	char	*path;

	(void)shell; // unused parameter
	// only 'cd' case
	if (argv_count(cmd->argv) < 2)
	{
		ft_putstr(2, "minishell: cd: missing argument\n");
		return (1);
	}
	// extra argument case
	if (argv_count(cmd->argv) > 2)
	{
		ft_putstr(2, "minishell: cd: too many arguments\n");
		return (1);
	}
	// get the path
	path = cmd->argv[1];
	// uses the chdir function that 
	// changes the current working directory
	if (chdir(path) != 0)
	{
		// otherwise if the directory is not found
		// print, error and return 1
		ft_putstr(2, "minishell: cd: ");
		perror(path);
		return (1);
	}
	return (0);
}
