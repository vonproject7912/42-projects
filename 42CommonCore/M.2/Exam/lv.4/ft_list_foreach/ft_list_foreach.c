/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_foreach.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vonpr <vonpr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 11:20:24 by vonpr             #+#    #+#             */
/*   Updated: 2026/04/10 15:40:17 by vonpr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

typedef struct s_list
{
	struct s_list	*next;
	void			*data;
}					t_list;

void	ft_list_foreach(t_list *begin_list, void (*f)(void *))
{
	while (begin_list != NULL)
	{
		if (begin_list->data != NULL)
			(*f)(begin_list->data);
		begin_list = begin_list->next;
	}
}
