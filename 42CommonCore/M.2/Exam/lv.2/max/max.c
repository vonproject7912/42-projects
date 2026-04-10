/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vonpr <vonpr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 10:47:31 by vonpr             #+#    #+#             */
/*   Updated: 2026/04/10 15:36:03 by vonpr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int	max(int *tab, unsigned int len)
{
	int				max;
	unsigned int	i;

	i = 0;
	if (len == 0 || !tab)
		return (0);
	max = tab[i];
	while (i <= len)
	{
		if (tab[i + 1] > max)
			max = tab[i + 1];
		i++;
	}
	return (max);
}

int	main(void)
{
	int	tab[7] = {3, 6, 84, 999, 7912, 4, 9999};

	printf("%d", max(tab, 7));
	return (0);
}
