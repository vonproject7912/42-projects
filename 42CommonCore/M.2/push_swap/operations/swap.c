/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vonpr <vonpr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 09:49:49 by vonpr             #+#    #+#             */
/*   Updated: 2026/04/10 15:57:43 by vonpr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// swap a stack
void	swap(t_list *stack)
{
	int		hold;
	t_list	*tmp;

	tmp = stack->next;
	hold = tmp->content;
	tmp->content = stack->content;
	stack->content = hold;
}

// swap a
void	swap_a(t_list *stack_a)
{
	swap(stack_a);
	ft_putstr("sa\n");
}

// swap b
void	swap_b(t_list *stack_b)
{
	swap(stack_b);
	ft_putstr("sb\n");
}

// swap both
void	swap_both(t_list *stack_a, t_list *stack_b)
{
	if (!stack_a || !stack_b)
		return ;
	swap_a(stack_a);
	swap_b(stack_b);
	ft_putstr("ss\n");
}
