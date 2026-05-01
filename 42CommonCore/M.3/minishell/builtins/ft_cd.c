/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vonpr <vonpr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 09:50:07 by vonpr             #+#    #+#             */
/*   Updated: 2026/05/01 10:02:26 by vonpr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	argv_count(char **argv)
{
	int	count;

	count = 0;
	while (argv[count])
		count++;
	return (count);
}

int	ft_cd(t_shell *shell, t_cmd *cmd)
{
	char	*path;

	(void)shell;
	if (argv_count(cmd->argv) < 2)
	{
		ft_putstr(2, "minishell: cd: missing argument\n");
		return (1);
	}
	if (argv_count(cmd->argv) > 2)
	{
		ft_putstr(2, "minishell: cd: too many arguments\n");
		return (1);
	}
	path = cmd->argv[1];
	if (chdir(path) != 0)
	{
		ft_putstr(2, "minishell: cd: ");
		perror(path);
		return (1);
	}
	return (0);
}
