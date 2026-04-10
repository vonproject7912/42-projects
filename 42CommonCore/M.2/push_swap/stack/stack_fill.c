/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vonpr <vonpr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 18:53:28 by vonpr             #+#    #+#             */
/*   Updated: 2026/04/10 15:59:59 by vonpr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// regular node creation + assign
t_list	*new_node(int nbr)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->content = nbr;
	node->next = NULL;
	return (node);
}

// add a node in the end
void	lst_add_back(t_list **lst, t_list *to_add)
{
	t_list	*current;

	if (!*lst)
	{
		*lst = to_add;
		return ;
	}
	current = *lst;
	while (current->next != NULL)
		current = current->next;
	current->next = to_add;
}

// fill the stack with the tab
t_list	*stack_fill(int *tab, int size)
{
	int		i;
	t_list	*stack_a;

	i = 0;
	stack_a = NULL;
	while (i < size)
	{
		lst_add_back(&stack_a, new_node(tab[i]));
		i++;
	}
	return (stack_a);
}
