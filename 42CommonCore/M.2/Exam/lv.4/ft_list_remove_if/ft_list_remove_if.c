/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vonpr <vonpr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 11:20:57 by vonpr             #+#    #+#             */
/*   Updated: 2026/04/10 15:40:26 by vonpr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// for NULL
#include <stddef.h>

typedef struct s_list
{
	struct s_list	*next;
	int				data;
}					t_list;

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list	*current;

	if (begin_list == NULL || *begin_list == NULL)
		return ;
	current = *begin_list;
	// if data match data_ref we move forward and free current
	if (cmp(current->data, data_ref) == 0)
	{
		*begin_list = current->next;
		free(current); // on le free
		// call the function over (backtracking)
		ft_list_remove_if(begin_list, data_ref, cmp);
	}
	current = *begin_list;
	ft_list_remove_if(&current->next, data_ref, cmp);
}
