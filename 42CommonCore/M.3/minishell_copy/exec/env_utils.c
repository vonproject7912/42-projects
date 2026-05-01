/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vonpr <vonpr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 08:18:49 by vonpr             #+#    #+#             */
/*   Updated: 2026/05/01 12:50:59 by vonpr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// count how many lines there are
// in the actual environnement array
int	env_count(char **envp)
{
	int	count;

	count = 0;
	while (envp && envp[count])
		count++;
	return (count);
}

// return the lenght of the key 
// before the '=' signe 
int	key_len(char *entry)
{
	int	i;

	i = 0;
	while (entry[i] && entry[i] != '=')
		i++;
	return (i);
}

// check if a string in the env matches a specific key
int	env_key_match(char *entry, char *key, int len)
{
	// ensure the key actually matches
	// check that there is a '=' or a '\0'
	// after the actual key
	return (!ft_strncmp(entry, key, len)
		&& (entry[len] == '=' || entry[len] == '\0'));
}

// add a new variable to the end of the environment array
int	env_append(t_shell *shell, char *entry, int count)
{
	int		i;
	char	**new_env;

	// malloc a new environnment array
	new_env = malloc(sizeof(char *) * (count + 2));
	if (!new_env) // small check
		return (1);
	i = -1; // starter
	// while the environment exits, copy each
	// lines 
	while (shell->envp && shell->envp[++i])
		new_env[i] = shell->envp[i];
	// if i is still -1, set it to 0
	if (i < 0)
		i = 0;
	// add the new variable
	new_env[i] = ft_strdup(entry);
	// last line is NULL
	new_env[i + 1] = NULL;
	// free the old env
	free(shell->envp);
	// add up the new one
	shell->envp = new_env;
	// return 1 if the strdup failed
	return (new_env[i] == NULL);
}
