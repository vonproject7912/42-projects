/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vonpr <vonpr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 22:34:30 by vonpr             #+#    #+#             */
/*   Updated: 2026/04/10 15:53:35 by vonpr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// error printing on fd 2
void	error_mess(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(2, &str[i], 1);
		i++;
	}
}

// regular strncmp
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((s1[i] || s2[i]) && i < n)
	{
		if ((unsigned char)s1[i] != (unsigned char)s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

// get the sign
// we passed the adress of i to overwrite it
static int	get_sign(char *str, int *i)
{
	int	signe;

	signe = 1;
	while (str[*i] == '-' || str[*i] == '+')
	{
		if (str[*i] == '-')
			signe *= -1;
		(*i)++;
	}
	return (signe);
}

// convert into a double long int
double	atodbl(char *str)
{
	int		i;
	int		signe;
	long	integer;
	double	virgule;
	double	fractional_part;

	i = 0;
	virgule = 1;
	integer = 0;
	fractional_part = 0;
	while (str[i] && ((str[i] >= '\t' && str[i] <= '\r') || str[i] == ' '))
		i++;
	signe = get_sign(str, &i);
	// Build the integer part
	while (str[i] && str[i] != '.' && (str[i] >= '0' && str[i] <= '9'))
		integer = integer * 10 + (str[i++] - '0');
	// skip the decimal point
	if (str[i] == '.')
		i++;
	// Build the fractional part
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		virgule /= 10; // reduce the power of ten (0.1 to 0.01 etc.)
		fractional_part = fractional_part + (str[i++] - '0') * (virgule);
	}
	return ((integer + fractional_part) * signe);
}
