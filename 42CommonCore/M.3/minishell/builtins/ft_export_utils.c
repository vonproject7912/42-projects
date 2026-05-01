/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vonpr <vonpr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 09:53:00 by vonpr             #+#    #+#             */
/*   Updated: 2026/05/01 09:53:23 by vonpr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_valid_identifier(char *str)
{
	int	i;

	if (!str || (!((str[0] >= 'A' && str[0] <= 'Z') || (str[0] >= 'a'
					&& str[0] <= 'z') || str[0] == '_')))
		return (0);
	i = 1;
	while (str[i] && str[i] != '=')
	{
		if (!((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a'
					&& str[i] <= 'z') || (str[i] >= '0' && str[i] <= '9')
				|| str[i] == '_'))
			return (0);
		i++;
	}
	return (1);
}

void	print_export(char **envp)
{
	int		i;
	char	*equal;

	i = 0;
	while (envp && envp[i])
	{
		equal = ft_strchr(envp[i], '=');
		ft_putstr(1, "declare -x ");
		if (equal)
		{
			write(1, envp[i], equal - envp[i] + 1);
			ft_putstr(1, "\"");
			ft_putstr(1, equal + 1);
			ft_putstr(1, "\"");
		}
		else
			ft_putstr(1, envp[i]);
		ft_putstr(1, "\n");
		i++;
	}
}
