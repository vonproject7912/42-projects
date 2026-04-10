/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_index.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vonpr <vonpr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 18:53:39 by vonpr             #+#    #+#             */
/*   Updated: 2026/04/10 15:59:57 by vonpr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// set all indexes to -1
void	initialize_index(t_list *stack_a)
{
	t_list	*current;

	current = stack_a;
	while (current != NULL)
	{
		current->index = -1;
		current = current->next;
	}
}

// find the minimum
t_list	*min_finder(t_list *stack_a)
{
	t_list	*tmp_min;
	t_list	*forward;

	tmp_min = NULL;
	forward = stack_a;
	while (forward != NULL)
	{
		// only if the index hasn't been assgined
		if (forward->index == -1)
		{
			// if first check assign
			if (tmp_min == NULL)
				tmp_min = forward;
			// otherwise compare all digits
			else if (forward->content < tmp_min->content)
				tmp_min = forward;
		}
		forward = forward->next;
	}
	return (tmp_min);
}

// get the stack's size
int	lst_size(t_list *stack_a)
{
	int		size;
	t_list	*current;

	size = 0;
	current = stack_a;
	while (current != NULL)
	{
		size++;
		current = current->next;
	}
	return (size);
}

// loop over each index assigning them
void	assign_index(t_list *stack_a)
{
	int		i;
	int		size;
	t_list	*actual_min;

	i = 0;
	size = lst_size(stack_a);
	initialize_index(stack_a);
	while (i < size)
	{
		actual_min = min_finder(stack_a);
		actual_min->index = i;
		i++;
	}
}
