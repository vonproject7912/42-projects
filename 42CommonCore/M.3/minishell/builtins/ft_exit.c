/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vonpr <vonpr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 09:50:36 by vonpr             #+#    #+#             */
/*   Updated: 2026/05/01 10:02:38 by vonpr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	is_numeric(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

static int	ft_atoi_exit(char *str)
{
	int					i;
	int					sign;
	unsigned long long	value;

	i = 0;
	sign = 1;
	value = 0;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i])
		value = value * 10 + (str[i++] - '0');
	return ((int)((value * sign) & 255));
}

int	ft_exit(t_shell *shell, t_cmd *cmd)
{
	ft_putstr(1, "exit\n");
	if (cmd->argv[1] && !is_numeric(cmd->argv[1]))
	{
		ft_putstr(2, "minishell: exit: numeric argument required\n");
		shell->last_exit = 2;
	}
	else if (cmd->argv[1] && cmd->argv[2])
	{
		ft_putstr(2, "minishell: exit: too many arguments\n");
		return (1);
	}
	else if (cmd->argv[1])
		shell->last_exit = ft_atoi_exit(cmd->argv[1]);
	shell->should_exit = 1;
	return (shell->last_exit);
}
