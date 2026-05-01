/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vonpr <vonpr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 09:50:55 by vonpr             #+#    #+#             */
/*   Updated: 2026/05/01 13:23:32 by vonpr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// the implementation of the pwd builtin
int	ft_pwd(void)
{
	char	buffer[4096];
	// 4096 is a standard "PATH_MAX" limit on linux

	// getcwp is a function that get the 
	// current working directory into a buffer
	if (!getcwd(buffer, sizeof(buffer)))
	{
		perror("minishell: pwd");
		return (1);
	}
	// print the buffer
	ft_putstr(1, buffer);
	// print a new_line
	ft_putstr(1, "\n");
	return (0);
}
