/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vonpr <vonpr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 01:13:54 by vonpr             #+#    #+#             */
/*   Updated: 2026/04/10 15:22:01 by vonpr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// if upercase put into lowercase
int	ft_tolower(int letter)
{
	if (letter >= 'A' && letter <= 'Z')
		return (letter + 32);
	return (letter);
}
