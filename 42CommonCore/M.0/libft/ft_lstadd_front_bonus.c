/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vonpr <vonpr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 04:32:45 by vonpr             #+#    #+#             */
/*   Updated: 2026/04/10 15:16:43 by vonpr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// adds a new node in front of the list
void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst && new)
	{
		// new node points to the current first node
		new->next = *lst;
		// new node becomes the first node
		*lst = new;
	}
}
