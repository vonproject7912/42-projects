/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vonpr <vonpr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 09:48:45 by vonpr             #+#    #+#             */
/*   Updated: 2026/04/10 15:57:35 by vonpr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// reverse a stack
void	reverse(t_list **stack)
{
	t_list	*old_head;
	t_list	*tmp_last;
	t_list	*real_last;

	tmp_last = *stack;
	real_last = *stack;
	old_head = *stack;
	while (tmp_last->next != NULL)
		tmp_last = tmp_last->next;
	while (real_last->next->next != NULL)
		real_last = real_last->next;
	*stack = tmp_last;
	tmp_last->next = old_head;
	real_last->next = NULL;
}

// reverse a
void	reverse_a(t_list **stack_a)
{
	reverse(stack_a);
	ft_putstr("rra\n");
}

// reverse b
void	reverse_b(t_list **stack_b)
{
	reverse(stack_b);
	ft_putstr("rrb\n");
}

// reverse both
void	rev_rev(t_list **stack_a, t_list **stack_b)
{
	if (!stack_a || !stack_b)
		return ;
	reverse_a(stack_a);
	reverse_b(stack_b);
	ft_putstr("rrr\n");
}
