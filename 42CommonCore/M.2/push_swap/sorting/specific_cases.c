/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specific_cases.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vonpr <vonpr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 18:50:36 by vonpr             #+#    #+#             */
/*   Updated: 2026/04/10 15:59:06 by vonpr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// 2 digit case
void	is_two(t_list **stack_a)
{
	swap_a(*stack_a);
}

// 3 digit case
void	is_three(t_list **stack_a)
{
	t_list	*first;
	t_list	*second;
	t_list	*last;

	first = *stack_a;
	second = (*stack_a)->next;
	last = (*stack_a)->next->next;
	if (second->index > last->index && last->index > first->index)
	{
		reverse_a(stack_a);
		swap_a(*stack_a);
	}
	else if (second->index > first->index && first->index > last->index)
		reverse_a(stack_a);
	else if (last->index > first->index && first->index > second->index)
		swap_a(*stack_a);
	else if (first->index > second->index && second->index > last->index)
	{
		swap_a(*stack_a);
		reverse_a(stack_a);
	}
	else if (first->index > last->index && last->index > second->index)
		rotate_a(stack_a);
}

// 4 digit case
void	is_four(t_list **stack_a, t_list **stack_b)
{
	min_to_top_4(stack_a);
	push_b(stack_a, stack_b);
	assign_index(*stack_a);
	is_three(stack_a);
	push_a(stack_b, stack_a);
}

// 5 digit case
void	is_five(t_list **stack_a, t_list **stack_b)
{
	min_to_top_5(stack_a);
	push_b(stack_a, stack_b);
	assign_index(*stack_a);
	min_to_top_4(stack_a);
	push_b(stack_a, stack_b);
	assign_index(*stack_a);
	is_three(stack_a);
	push_a(stack_b, stack_a);
	push_a(stack_b, stack_a);
}
