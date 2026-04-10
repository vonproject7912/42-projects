/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking_moving.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vonpr <vonpr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 18:37:12 by vonpr             #+#    #+#             */
/*   Updated: 2026/04/10 15:59:04 by vonpr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// check if the stack is sorted
int	is_sorted(t_list *stack_a)
{
	t_list	*current;
	t_list	*after_current;

	current = stack_a;
	after_current = stack_a->next;
	while (after_current != NULL)
	{
		if (current->index > after_current->index)
			return (0);
		current = current->next;
		after_current = after_current->next;
	}
	return (1);
}

// find the least significant number in the stack
t_list	*find_min_stack(t_list *stack_a)
{
	t_list	*forward;
	t_list	*tmp_min;

	tmp_min = NULL;
	forward = stack_a;
	while (forward != NULL)
	{
		// if it's the first check assign
		if (tmp_min == NULL)
			tmp_min = forward;
		// otherwise compare all indexes
		else if (forward->index < tmp_min->index)
			tmp_min = forward;
		forward = forward->next;
	}
	return (tmp_min);
}

// put the minimum on top of a Stack of 4
void	min_to_top_4(t_list **stack_a)
{
	t_list	*second;
	t_list	*third;
	t_list	*fourth;
	t_list	*min;

	min = find_min_stack(*stack_a);
	second = (*stack_a)->next;
	third = (*stack_a)->next->next;
	fourth = (*stack_a)->next->next->next;
	if (min == second)
		swap_a(*stack_a);
	else if (min == third)
	{
		reverse_a(stack_a);
		reverse_a(stack_a);
	}
	else if (min == fourth)
		reverse_a(stack_a);
}

// put the minimum on top of a Stack of 5
void	min_to_top_5(t_list **stack_a)
{
	t_list	*min;
	t_list	*second;
	t_list	*third;
	t_list	*fourth;
	t_list	*fifth;

	min = find_min_stack(*stack_a);
	second = (*stack_a)->next;
	third = (*stack_a)->next->next;
	fourth = (*stack_a)->next->next->next;
	fifth = (*stack_a)->next->next->next->next;
	if (min == second)
		swap_a(*stack_a);
	else if (min == third)
	{
		rotate_a(stack_a);
		rotate_a(stack_a);
	}
	else if (min == fourth)
	{
		reverse_a(stack_a);
		reverse_a(stack_a);
	}
	else if (min == fifth)
		reverse_a(stack_a);
}
