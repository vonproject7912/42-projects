/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vonpr <vonpr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 08:12:46 by vonpr             #+#    #+#             */
/*   Updated: 2026/05/01 08:12:47 by vonpr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ms_is_blank(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '\t')
			return (0);
		i++;
	}
	return (1);
}

int	ms_read_line(char **line)
{
	*line = readline("minishell$ ");
	if (!*line)
	{
		ft_putstr(1, "exit\n");
		return (0);
	}
	if ((*line)[0])
		add_history(*line);
	return (1);
}
