/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vonpr <vonpr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 05:44:34 by vonpr             #+#    #+#             */
/*   Updated: 2026/04/10 15:27:50 by vonpr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

/* ---------- GNL ------------ */
void	search_line(char **stash, char *buf, char **tmp, int fd);
char	*build_line(char **stash);
char	*get_next_line(int fd);

/* ---------- UTILS ---------- */
size_t	ft_strlen(const char *str);
char	*ft_strdup(char *s);
long	search_n(char *str);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);

#endif