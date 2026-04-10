/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vonpr <vonpr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 03:24:33 by vonpr             #+#    #+#             */
/*   Updated: 2026/04/10 15:21:47 by vonpr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Same as ft_striteri but returns a new string instead of modifying in place
// — applies f(index, char) to each character and stores the results.
char	*ft_strmapi(char const *str, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*result;

	i = 0;
	if (!str || !f)
		return (NULL);
	result = malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (!result)
		return (NULL);
	while (str[i])
	{
		result[i] = f(i, str[i]);
		i++;
	}
	result[i] = '\0';
	return (result);
}
