/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vonpr <vonpr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 09:49:11 by vonpr             #+#    #+#             */
/*   Updated: 2026/04/10 15:57:40 by vonpr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// rotate a stack
void	rotate(t_list **stack)
{
	t_list	*tmp_last;
	t_list	*tmp_head;
	t_list	*final_head;

	tmp_head = *stack;
	tmp_last = *stack;
	final_head = (*stack)->next;
	while (tmp_last->next != NULL)
		tmp_last = tmp_last->next;
	tmp_last->next = tmp_head;
	tmp_head->next = NULL;
	*stack = final_head;
}

// rotate a
void	rotate_a(t_list **stack_a)
{
	rotate(stack_a);
	ft_putstr("ra\n");
}

// rotate b
void	rotate_b(t_list **stack_b)
{
	rotate(stack_b);
	ft_putstr("rb\n");
}

// rotate both
void	rotate_rotate(t_list **stack_a, t_list **stack_b)
{
	if (!stack_a || !stack_b)
		return ;
	rotate(stack_a);
	rotate(stack_b);
	ft_putstr("rr\n");
}
