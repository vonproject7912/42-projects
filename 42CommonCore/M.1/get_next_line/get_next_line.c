/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vonpr <vonpr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 00:54:38 by vonpr             #+#    #+#             */
/*   Updated: 2026/04/10 15:27:47 by vonpr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// reads from fd in BUFFER_SIZE chunks, appending each chunk
// to stash until a newline is found or EOF/error is reached
void	search_line(char **stash, char *buf, char **tmp, int fd)
{
	ssize_t	r;

	while (1)
	{
		// read a chunk
		r = read(fd, buf, BUFFER_SIZE);
		// exit if nothing left to read
		if (r == 0)
			break ;
		// error checking
		if (r == -1)
		{
			free(*stash);
			*stash = NULL;
			break ;
		}
		// null terminate the chunk
		buf[r] = '\0';
		// if first chunk, init the stash
		if (!*stash)
			*stash = ft_strdup(buf);
		else
		{
			// add what we've read to the stash
			*tmp = ft_strjoin(*stash, buf);
			free(*stash);
			// update the stash
			*stash = *tmp;
		}
		// newline found
		if (search_n(*stash) != -1)
			break ;
	}
}

// after reading through the line into chunck, substract only the line
char	*build_line(char **stash)
{
	ssize_t	len;
	char	*line;
	char	*tmp;

	// find the new_line's position
	len = search_n(*stash);
	// newline found
	if (len != -1)
	{
		// extract line including '\n'
		line = ft_substr(*stash, 0, (len + 1));
		// save what's left
		tmp = ft_strdup(*stash + len + 1);
		free(*stash);
		// stash old what's left
		*stash = tmp;
		return (line);
	}
	// no newline = terminated line
	line = ft_strdup(*stash);
	free(*stash);
	*stash = NULL;
	return (line);
}

// main function
char	*get_next_line(int fd)
{
	char		*tmp;
	char		*buf;
	static char	*stash;
	char		*final_line;

	tmp = NULL;
	// argument check
	if (fd < 0 || BUFFER_SIZE == 0)
		return (NULL);
	buf = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	// fill stash until '\n' or end of line
	search_line(&stash, buf, &tmp, fd);
	free(buf);
	// empty line case
	if (!stash || *stash == '\0')
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	// extract one line and update stash
	final_line = build_line(&stash);
	return (final_line);
}

/*
int	main(int argc, char **argv)
{
	int		fd;
	char	*line;

	// error case
	if (argc != 2)
	{
		printf("Usage: %s <file>\n", argv[0]);
		return (1);
	}
	// open the file
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		perror("open");
		return (1);
	}
	// read until the end of the file
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
	return (0);
}
*/