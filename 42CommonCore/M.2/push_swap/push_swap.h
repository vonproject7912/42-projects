/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vonpr <vonpr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 18:43:22 by vonpr             #+#    #+#             */
/*   Updated: 2026/04/10 16:01:41 by vonpr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct t_list
{
	int				content;
	int				index;
	struct t_list	*next;
}					t_list;

/*		Operations		*/
void				push(t_list **pushed, t_list **dest);
void				push_a(t_list **stack_b, t_list **stack_a);
void				push_b(t_list **stack_a, t_list **stack_b);
void				reverse(t_list **stack);
void				reverse_a(t_list **stack_a);
void				reverse_b(t_list **stack_b);
void				rev_rev(t_list **stack_a, t_list **stack_b);
void				rotate(t_list **stack);
void				rotate_a(t_list **stack_a);
void				rotate_b(t_list **stack_b);
void				rotate_rotate(t_list **stack_a, t_list **stack_b);
void				swap(t_list *stack);
void				swap_a(t_list *stack_a);
void				swap_b(t_list *stack_b);
void				swap_both(t_list *stack_a, t_list *stack_b);

/*			Parsing	  	*/
int					ft_strlen(char *str);
char				*ft_strdup(char *str);
char				*ft_strjoin(char *s1, char *s2);
int					ft_strcmp(char *s1, char *s2);
int					count_tab(char **tab);
char				*join_arg(int ac, char *av[]);
int					are_digits(char *str);
int					dups(char *target, char **tab, int index);
char				**prep_stack(int ac, char *av[]);
t_list				*parsing(char **tab);

/*			Sorting				*/
int					is_sorted(t_list *stack_a);
t_list				*find_min_stack(t_list *stack_a);
void				min_to_top_4(t_list **stack_a);
void				min_to_top_5(t_list **stack_a);
void				is_two(t_list **stack_a);
void				is_three(t_list **stack_a);
void				is_four(t_list **stack_a, t_list **stack_b);
void				is_five(t_list **stack_a, t_list **stack_b);

/*			Stack	 	*/
void				initialize_index(t_list *stack_a);
t_list				*min_finder(t_list *stack_a);
int					lst_size(t_list *stack_a);
void				assign_index(t_list *stack_a);
t_list				*new_node(int nbr);
void				lst_add_back(t_list **lst, t_list *to_add);
t_list				*stack_fill(int *tab, int size);

/*			tools			*/
void				ft_putstr(char *str);
void				error_msg(void);
int					count_words(const char *str, char c);
int					word_len(const char *str, char c);
void				free_tab(char **tab);
char				**ft_split(char const *str, char c);
long				atol(const char *str);
int					is_range(long nbr);

/*		RADIX HEHE       */
int					get_max_bits(int size);
void				sort_by_bit(t_list **stack_a, t_list **stack_b,
						int bit_index);
void				radix_sort(t_list **stack_a, t_list **stack_b);

/*       MAIN        */
void				free_stack(t_list *stack_a);
int					if_is_only_space(char *str);
void				pick_algo(t_list **stack_a, t_list **stack_b);
int					checkings(int ac, char *av[]);

#endif