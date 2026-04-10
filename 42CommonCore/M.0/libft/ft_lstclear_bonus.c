/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vonpr <vonpr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 04:25:54 by vonpr             #+#    #+#             */
/*   Updated: 2026/04/10 15:16:45 by vonpr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// freeing every node and clean up the whole lst
void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;
	t_list	*current;

	if (!lst || !del)
		return ;
	current = *lst;
	while (current != NULL)
	{
		tmp = current;
		current = current->next;
		del(tmp->content);
		free(tmp);
	}
	*lst = NULL;
}
