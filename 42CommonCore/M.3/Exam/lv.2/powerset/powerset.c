/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   powerset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vonpr <vonpr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 09:22:37 by vonpr             #+#    #+#             */
/*   Updated: 2026/04/13 09:48:38 by vonpr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "powerset.h"

int	main(int ac, char *av[])
{
	int	i;
	int	mask;
	int	input;
	int	first_nbr;
	int	sum_subset;
	int	target_sum;

	mask = 0;
	input = ac - 2;
	target_sum = atoi(av[1]);
	// Loop through all possible subsets (2^n)
	while (mask < (1 << input))
	{
		i = 0;
		sum_subset = 0;
		// Calculate sum of subset
		while (i < input)
		{
			// Check if i-th element is included in subset
			// if the result is 1 include it
			if ((mask >> i) & 1)
				sum_subset += atoi(av[2 + i]);
			i++;
		}
		// If subset sum matches target
		if (sum_subset == target_sum)
		{
			i = 0;
			first_nbr = 0;
			// Print subset elements
			while (i < input)
			{
				if ((mask >> i) & 1)
				{
					if (first_nbr)
						printf(" ");
					printf("%d", atoi(av[2 + i]));
					first_nbr = 1;
				}
				i++;
			}
			printf("\n");
		}
		// Move to next subset
		mask++;
	}
}

/*Use of bitmask:
We generate all possible subsets by treating each number from 0 to 2^n
	- 1 as a bitmask
where each bit indicates whether to include the corresponding element.

A bitmask is a binary number where each bit represents a choice,
	such as whether to
include or exclude an element in a subset.

=> for each bit that is 1,
	we include the corresponding element in the current subset.
*/