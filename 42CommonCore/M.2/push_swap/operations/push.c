/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vonpr <vonpr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 09:47:42 by vonpr             #+#    #+#             */
/*   Updated: 2026/04/10 15:57:32 by vonpr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// push a stack
void	push(t_list **pushed, t_list **dest)
{
	t_list	*pushed_first;
	t_list	*pushed_second;

	// check
	if (!pushed || !*pushed)
		return ;
	// make the push
	pushed_second = (*pushed)->next;
	pushed_first = *pushed;
	pushed_first->next = *dest;
	*dest = pushed_first;
	*pushed = pushed_second;
}

// push b into a
void	push_a(t_list **stack_b, t_list **stack_a)
{
	push(stack_b, stack_a);
	ft_putstr("pa\n");
}

// push a into b
void	push_b(t_list **stack_a, t_list **stack_b)
{
	push(stack_a, stack_b);
	ft_putstr("pb\n");
}
