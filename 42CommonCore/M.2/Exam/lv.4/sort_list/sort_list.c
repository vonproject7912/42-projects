/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vonpr <vonpr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 11:28:10 by vonpr             #+#    #+#             */
/*   Updated: 2026/04/10 15:49:42 by vonpr            ###   ########.fr       */
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

int	ascending(int a, int b)
{
	return (a <= b);
}

t_list	*sort_list(t_list *lst, int (*cmp)(int, int))
{
	int		tmp;
	int		test;
	t_list	*current;
	t_list	*current_2;

	current = lst;
	current_2 = lst->next;
	while (current_2->next != NULL)
	{
		test = cmp(current->data, current_2->data);
		if (test == 1)
		{
			current = current->next;
			current_2 = current_2->next;
		}
		else
		{
			tmp = current->data;
			current->data = current_2->data;
			current_2->data = tmp;
			// restart from beginning
			current = lst;
			current_2 = lst->next;
		}
	}
	return (0);
}

int	main(void)
{
	t_list	*node_1;
	t_list	*node_2;
	t_list	*node_3;

	node_1 = NULL;
	node_2 = NULL;
	node_3 = NULL;
	node_1 = malloc(sizeof(t_list));
	node_2 = malloc(sizeof(t_list));
	node_3 = malloc(sizeof(t_list));
	node_1->data = 7;
	node_2->data = 2;
	node_3->data = 9;
	node_1->next = node_2;
	node_2->next = node_3;
	node_3->next = NULL;
	sort_list(node_1, ascending);
	printf("%d", node_1->data);
	printf("%d", node_2->data);
	printf("%d", node_3->data);
	return (0);
}
