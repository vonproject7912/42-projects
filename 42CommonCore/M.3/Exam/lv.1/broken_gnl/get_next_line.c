/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vonpr <vonpr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 09:12:20 by vonpr             #+#    #+#             */
/*   Updated: 2026/04/10 16:08:17 by vonpr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// use a strdup to get the actual line into the heap
char	*strdup(const char *str)
{
	int		i;
	int		len;
	char	*dest;

	i = 0;
	len = 0;
	while (str[len])
		len++;
	dest = malloc(sizeof(char) * len + 1);
	if (!dest)
		return (NULL);
	while (str[i])
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

// actual function to get the line
char	*get_next_line(int fd)
{
	int			i;
	char		line[10000];
	static int	reading = 0;
	static int	buffers_i = 0;
	static char	buffer[BUFFER_SIZE];

	// my static variables !
	i = 0;
	// check if the fd or buffer's size is wrong
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	// infinite loop
	while (1)
	{
		// read into it to 'fill' the buffer
		if (buffers_i == reading)
		{
			reading = read(fd, buffer, BUFFER_SIZE);
			buffers_i = 0;
			// if there is an error or EOF
			if (reading <= 0)
				break ;
		}
		// write into line the bytes read previously
		line[i++] = buffer[buffers_i++];
		// check for an ended sentence
		if (buffer[buffers_i - 1] == '\n')
			break ;
	}
	if (i == 0)
		return (NULL);
	line[i] = '\0';
	return (strdup(line));
}

int	main(void)
{
	int		i;
	int		fd;
	char	*line;

	i = 0;
	fd = open("test.txt", O_RDONLY);
	while (i < 5)
	{
		line = get_next_line(fd);
		printf("Result %d: %s", i, line);
		i++;
	}
	return (0);
}
