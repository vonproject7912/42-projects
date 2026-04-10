/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if_clean.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vonpr <vonpr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 13:30:20 by vonpr             #+#    #+#             */
/*   Updated: 2026/04/10 15:42:15 by vonpr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h> // Pour le NULL

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
	if (cmp(current->data, data_ref) == 0)
	{
		*begin_list = current->next;
		free(current);
		ft_list_remove_if(begin_list, data_ref, cmp);
	}
	current = *begin_list;
	ft_list_remove_if(&current->next, data_ref, cmp);
}
