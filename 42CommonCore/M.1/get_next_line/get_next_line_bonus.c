/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vonpr <vonpr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 01:27:01 by vonpr             #+#    #+#             */
/*   Updated: 2026/04/10 15:27:38 by vonpr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

// same as the regular gnl but can read many files
// at the same time using a static stash as a 'tab'
void	search_line(char **stash, char *buf, char **tmp, int fd)
{
	ssize_t	r;

	while (1)
	{
		r = read(fd, buf, BUFFER_SIZE);
		if (r == 0)
			break ;
		if (r == -1)
		{
			free(*stash);
			*stash = NULL;
			break ;
		}
		buf[r] = '\0';
		if (!*stash)
			*stash = ft_strdup(buf);
		else
		{
			*tmp = ft_strjoin(*stash, buf);
			free(*stash);
			*stash = *tmp;
		}
		if (search_n(*stash) != -1)
			break ;
	}
}

char	*build_line(char **stash)
{
	ssize_t	len;
	char	*line;
	char	*tmp;

	len = search_n(*stash);
	if (len != -1)
	{
		line = ft_substr(*stash, 0, (len + 1));
		tmp = ft_strdup(*stash + len + 1);
		free(*stash);
		*stash = tmp;
		return (line);
	}
	line = ft_strdup(*stash);
	free(*stash);
	*stash = NULL;
	return (line);
}

char	*get_next_line(int fd)
{
	char		*tmp;
	char		*buf;
	static char	*stash[4096];
	char		*final_line;

	tmp = NULL;
	// also check the file / fd
	if (fd < 0 || BUFFER_SIZE == 0 || fd >= 4096)
		return (NULL);
	buf = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	// search the line of the file / fd
	search_line(&stash[fd], buf, &tmp, fd);
	free(buf);
	// empty line of the file / fd
	if (!stash[fd] || stash[fd][0] == '\0')
	{
		free(stash[fd]);
		stash[fd] = NULL;
		return (NULL);
	}
	// return the file's line
	final_line = build_line(&stash[fd]);
	return (final_line);
}
