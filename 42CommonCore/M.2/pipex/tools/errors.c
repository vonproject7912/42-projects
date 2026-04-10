/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vonpr <vonpr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 19:08:45 by vonpr             #+#    #+#             */
/*   Updated: 2026/04/10 15:55:37 by vonpr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	safe_closing(int fd)
{
	if (fd >= 0)
		close(fd);
}

void	arg_issue(t_pipex *folder)
{
	write(2, "Not the right number of arguments", 34);
	free(folder);
	exit(1);
}

void	error_regular_exit(char *mess)
{
	perror(mess);
	exit(1);
}

void	error_exit_fd(char *mess, t_pipex *folder)
{
	perror(mess);
	safe_closing(folder->infile);
	free(folder);
	exit(1);
}

void	full_error(char *mess, t_pipex *folder)
{
	perror(mess);
	safe_closing(folder->infile);
	safe_closing(folder->outfile);
	free(folder);
	exit(1);
}
