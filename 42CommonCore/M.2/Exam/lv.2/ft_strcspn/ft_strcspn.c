/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcspn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vonpr <vonpr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 10:43:34 by vonpr             #+#    #+#             */
/*   Updated: 2026/04/10 15:35:00 by vonpr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

size_t	ft_strcspn(const char *str, const char *reject)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (reject[j])
		{
			if (str[i] == reject[j])
				return (i);
			j++;
		}
		i++;
	}
	return (i);
}
