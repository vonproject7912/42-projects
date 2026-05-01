/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vonpr <vonpr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 09:53:00 by vonpr             #+#    #+#             */
/*   Updated: 2026/05/01 15:21:24 by vonpr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// checks if a string is a valid name for a shell variable
// it must start with a letter or underscore and can only 
// contain letters, numbers or underscores afterwards
int	is_valid_identifier(char *str)
{
	int	i;

	// checks the start of the name
	if (!str || (!((str[0] >= 'A' && str[0] <= 'Z') || (str[0] >= 'a'
					&& str[0] <= 'z') || str[0] == '_')))
		return (0); // otherwise return 1
	i = 1; // skip the first letter
	// loop over the string name and until '='
	while (str[i] && str[i] != '=')
	{
		// can be the alphabet, a digit or a underscore 
		if (!((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a'
					&& str[i] <= 'z') || (str[i] >= '0' && str[i] <= '9')
				|| str[i] == '_'))
			return (0);
		i++;
	}
	// valid identifier found
	return (1);
}

// print the environment variable in the 'export' format
// example format: declare -x USER="root"
void	print_export(char **envp)
{
	int		i;
	char	*equal;

	i = 0;
	// loop over the environment
	while (envp && envp[i])
	{
		// find if there is an '=' in the string
		// (check if it has a value)
		equal = ft_strchr(envp[i], '=');
		// write the start of the export format
		ft_putstr(1, "declare -x ");
		// if there is a '='
		if (equal)
		{
			// write(1, start_of_string, length_up_to_and_including_equal_sign)
			write(1, envp[i], equal - envp[i] + 1);
			// open quotes for value
			ft_putstr(1, "\"");
			// write the actual value after '='
			ft_putstr(1, equal + 1);
			// closing quotes for value
			ft_putstr(1, "\"");
		}
		// otherwise
		else // just print the variable name
			ft_putstr(1, envp[i]);
		ft_putstr(1, "\n");
		i++;
	}
}
