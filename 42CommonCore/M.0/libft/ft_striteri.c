/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vonpr <vonpr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 01:41:08 by vonpr             #+#    #+#             */
/*   Updated: 2026/04/10 15:21:28 by vonpr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Applies a function to each character of a string, with its index and address.
void	ft_striteri(char *str, void (*f)(unsigned int, char *))
{
	size_t	i;

	i = 0;
	if (!str || !f)
		return ;
	while (str[i])
	{
		f(i, &str[i]);
		i++;
	}
}
