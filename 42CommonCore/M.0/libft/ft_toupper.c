/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vonpr <vonpr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 00:31:33 by vonpr             #+#    #+#             */
/*   Updated: 2026/04/10 15:22:03 by vonpr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// if lowercase put into uppercase
int	ft_toupper(int letter)
{
	if (letter >= 'a' && letter <= 'z')
		return (letter - 32);
	return (letter);
}
