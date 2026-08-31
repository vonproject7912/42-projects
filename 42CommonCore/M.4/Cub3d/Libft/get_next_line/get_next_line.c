/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokhadra <mokhadra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 22:52:47 by mokhadra          #+#    #+#             */
/*   Updated: 2026/01/11 14:00:39 by mokhadra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	find_line(char **stash, char *buf, char **tmp, int fd)
{
	ssize_t	r;

	while (1)
	{
		r = read(fd, buf, BUFFER_SIZE);
		if (r == -1)
		{
			free(*stash);
			*stash = NULL;
			break ;
		}
		if (r == 0)
			break ;
		buf[r] = '\0';
		if (!*stash)
			*stash = ft_strdup_g(buf);
		else
		{
			*tmp = ft_strjoin_g(*stash, buf);
			free(*stash);
			*stash = *tmp;
		}
		if (search_n(*stash) != -1)
			break ;
	}
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*buf;
	char		*tmp;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	tmp = NULL;
	find_line(&stash, buf, &tmp, fd);
	free(buf);
	if (!stash || *stash == '\0')
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	line = extract_line_from_stash(&stash);
	return (line);
}

char	*extract_line_from_stash(char **stash)
{
	int		len;
	char	*line;
	char	*tmp;

	len = search_n(*stash);
	if (len != -1)
	{
		line = ft_substr_g(*stash, 0, len + 1);
		tmp = ft_strdup_g(*stash + len + 1);
		free(*stash);
		*stash = tmp;
		return (line);
	}
	line = ft_strdup_g(*stash);
	free(*stash);
	*stash = NULL;
	return (line);
}

// int main(int ac, char **av)
// {
//     if (ac != 2)
//     {
//         printf("Usage: %s <file>\n", av[0]);
//         return (1);
//     }

//     int fd = open(av[1], O_RDONLY);
//     if (fd < 0)
//     {
//         perror("open");
//         return (1);
//     }

//     char *line = get_next_line(fd);
//     if (line)
//     {
//         printf("%s", line);
//         free(line);
//     }
// 	line = get_next_line(fd);
//     if (line)
//     {
//         printf("%s", line);
//         free(line);
//     }
// 	line = get_next_line(fd);
//     if (line)
//     {
//         printf("%s", line);
//         free(line);
//     }
// 	get_next_line(-1);
//     close(fd);
//     return (0);
// }
