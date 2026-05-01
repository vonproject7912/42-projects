/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vonpr <vonpr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 12:22:46 by vonpr             #+#    #+#             */
/*   Updated: 2026/05/01 11:56:52 by vonpr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// check if a the first character of a variable is valid
// must start by a letter or a underscore and not a number
int	is_var_start(char c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || c == '_')
		return (1);
	return (0);
}

// checks if a character is valid for the rest the variable name
// a digit now acceptable for the rest
int	is_var_char(char c)
{
	if (is_var_start(c) || (c >= '0' && c <= '9'))
		return (1);
	return (0);
}

// helper function to put together the string and the variable
// joins the result built so far with the new part the free the old one 
char	*append_part(char *result, char *part)
{
	char	*new_result;

	if (!part) // small check
		return (free(result), NULL);
	// join the result and the new part
	new_result = ft_strjoin(result, part);
	// free both of them
	free(result);
	free(part);
	// return the new string
	return (new_result);
}

// search the environnement for a specific key / variable's name
char	*get_env_value(char *key, char **env)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(key);
	while (env && env[i])
	{
		// if the env matches the key and the next char is '='
		// ensuring that we didn't match a prefix
		if (!ft_strncmp(env[i], key, len) && env[i][len] == '=')
			return (env[i] + len + 1); // return the pointer to start of
			// the actual value of the variable after the '='
		i++;
	}
	// otherwise return an empty string
	return ("");
}
