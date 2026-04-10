/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vonpr <vonpr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 13:30:26 by vonpr             #+#    #+#             */
/*   Updated: 2026/04/10 15:42:23 by vonpr            ###   ########.fr       */
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

	if (begin_list == NULL || *begin_list == NULL) // securite
		return ;
	current = *begin_list;
	if (cmp(current->data, data_ref) == 0)
		// si la data du maillon correspond a la data_ref on free cur
	{
		*begin_list = current->next;                 
			// on saute le maillon qu'on free
		free(current);                                // on le free
		ft_list_remove_if(begin_list, data_ref, cmp); // on rapelle la fonction
	}
	current = *begin_list;
		// si la valeur n'est pas la meme on l'execute avec &cur->next
	ft_list_remove_if(&current->next, data_ref, cmp);
}
