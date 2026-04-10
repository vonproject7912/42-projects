/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strspn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vonpr <vonpr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 10:46:19 by vonpr             #+#    #+#             */
/*   Updated: 2026/04/10 15:35:30 by vonpr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

size_t	ft_strspn(const char *str, const char *accept)
{
	int	i;
	int	j;
	int	check;

	i = 0;
	while (str[i])
	{
		j = 0;
		check = 0;
		while (accept[j])
		{
			if (str[i] == accept[j])
				check = 1;
			j++;
		}
		if (check == 0)
			return (i);
		i++;
	}
	return (i);
}
