/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vonpr <vonpr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 04:33:51 by vonpr             #+#    #+#             */
/*   Updated: 2026/04/10 15:16:39 by vonpr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// adds a new node at the end of the list
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (!lst)
		return ;
	// if list is empty, new node becomes the first
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	// find the last node
	last = ft_lstlast(*lst);
	// append new node after it
	last->next = new;
}
