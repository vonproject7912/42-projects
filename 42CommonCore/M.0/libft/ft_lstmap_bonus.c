/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vonpr <vonpr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 04:09:04 by vonpr             #+#    #+#             */
/*   Updated: 2026/04/10 15:17:00 by vonpr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// apllies a function to each node of an existing list
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_node;
	void	*new_content;

	if (!lst || !f)
		return (NULL);
	new_list = NULL;
	while (lst)
	{
		// transform content
		new_content = f(lst->content);
		// create new node
		new_node = ft_lstnew(new_content);
		if (!new_node)
		{
			// free transformed content
			del(new_content);
			// free all nodes built so far
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		// append to new list
		ft_lstadd_back(&new_list, new_node);
		// i++;
		lst = lst->next;
	}
	return (new_list);
}
