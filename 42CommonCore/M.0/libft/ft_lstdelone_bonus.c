/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vonpr <vonpr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 04:10:35 by vonpr             #+#    #+#             */
/*   Updated: 2026/04/10 15:16:47 by vonpr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// It frees a single node by delegating the content cleanup to the provided
// del function, then freeing the node itself.
void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	// free the content
	del(lst->content);
	// free the node itself
	free(lst);
}

void	del_content(void *content)
{
	// free the node's content
	free(content);
}

/*
The two functions are completely independent — del_content is just an example of a function that
could be passed as the del parameter to ft_lstdelone,
	but there is no direct link between them.
You could pass any other compatible function instead.
*/