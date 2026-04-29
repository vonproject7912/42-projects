/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_two.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vonpr <vonpr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 14:02:13 by vonpr             #+#    #+#             */
/*   Updated: 2026/04/29 14:07:50 by vonpr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int	ft_strncmp(char *s1, char *s2, int n)
{
	int	i;

	i = 0;
	if (n <= 0)
		return (0);
	while (i < n - 1 && s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

char	*ft_strchr(char *str, int c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == (char)c)
			return (&str[i]);
		i++;
	}
	if ((char)c == '\0')
		return (&str[i]);
	return (NULL);
}

char	*ft_itoa(int n)
{
	int		i;
	long	nbr;
	int		sign;
	char	buffer[12];

	i = 11;
	nbr = n;
	sign = 1;
	buffer[i--] = '\0';
	if (nbr == 0)
		buffer[i--] = '0';
	if (nbr < 0)
	{
		sign = -1;
		nbr = -nbr;
	}
	while (nbr > 0)
	{
		buffer[i--] = (nbr % 10) + '0';
		nbr /= 10;
	}
	if (sign < 0)
		buffer[i--] = '-';
	return (ft_strdup(&buffer[i + 1]));
}
