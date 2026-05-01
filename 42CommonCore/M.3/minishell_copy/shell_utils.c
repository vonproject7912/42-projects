/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vonpr <vonpr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 08:12:46 by vonpr             #+#    #+#             */
/*   Updated: 2026/05/01 12:04:56 by vonpr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// check if a line is empty or only contains whitespaces
// prevents the shell from trying to execute a "nothing" command
int	ms_is_blank(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		// if there is anything other than spaces or tab
		if (line[i] != ' ' && line[i] != '\t')
			return (0); // then return
		i++;
	}
	return (1);
}

// display the prompt and read the user's input using the
// the Readline library
int	ms_read_line(char **line)
{
	// prints as a prompt "minishell$"
	// also read the user's input into line
	*line = readline("minishell$ ");
	if (!*line)
	{
		// if the line is empty meaning
		// ctrl + D has been pressed
		ft_putstr(1, "exit\n");
		return (0); // print exit
	}
	// otherwise if the line has content actually
	// stock it into the history
	if ((*line)[0])
		add_history(*line);
	return (1);
}
