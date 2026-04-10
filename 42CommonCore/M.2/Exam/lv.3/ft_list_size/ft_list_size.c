/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vonpr <vonpr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 11:06:34 by vonpr             #+#    #+#             */
/*   Updated: 2026/04/10 15:45:50 by vonpr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s_list
{
	struct s_list	*next;
	int				data;
}					t_list;

int	ft_list_size(t_list *begin_list)
{
	int		count;
	t_list	*current;

	count = 0;
	current = begin_list;
	if (!begin_list)
		return (0);
	while (current != NULL)
	{
		current = current->next;
		count++;
	}
	return (count);
}

int	main(void)
{
	t_list	*node_0;
	t_list	*node_1;
	t_list	*node_2;

	node_0 = malloc(sizeof(t_list));
	node_1 = malloc(sizeof(t_list));
	node_2 = malloc(sizeof(t_list));
	node_0->data = 7;
	node_0->data = 7;
	node_0->data = 7;
	node_0->next = node_1;
	node_1->next = node_2;
	node_2->next = NULL;
	printf("%d", ft_list_size(node_0));
	return (0);
}
