/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vonpr <vonpr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 19:00:37 by vonpr             #+#    #+#             */
/*   Updated: 2026/04/10 16:01:45 by vonpr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// get the maximum of bits
int	get_max_bits(int size)
{
	int	bits;

	bits = 0;
	while ((size - 1) >> bits)
		bits++;
	return (bits);
}

// as the name implies
void	sort_by_bit(t_list **stack_a, t_list **stack_b, int bit_index)
{
	int	size;
	int	i;

	i = 0;
	size = lst_size(*stack_a);
	while (i < size)
	{
		// Stack B takes 0
		if ((((*stack_a)->index >> bit_index) & 1) == 0)
			push_b(stack_a, stack_b);
		// Stack A takes 1
		else
			rotate_a(stack_a);
		i++;
	}
	// push everything back into 1
	while (*stack_b)
		push_a(stack_b, stack_a);
}

// loop over each bits
void	radix_sort(t_list **stack_a, t_list **stack_b)
{
	int	max_bits;
	int	bit;

	bit = 0;
	max_bits = get_max_bits(lst_size(*stack_a));
	while (bit < max_bits)
	{
		sort_by_bit(stack_a, stack_b, bit);
		bit++;
	}
}
