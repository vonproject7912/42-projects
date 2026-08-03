/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vonpr <vonpr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 08:19:45 by vonpr             #+#    #+#             */
/*   Updated: 2026/05/01 13:06:33 by vonpr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// create a copy of the system env
char	**env_dup(char **envp)
{
	int		i;
	char	**copy;

	// allocate an array based on the system's size
	copy = malloc(sizeof(char *) * (env_count(envp) + 1));
	if (!copy) // small check
		return (NULL);
	i = 0;
	// loop over the systemn environment
	while (envp && envp[i])
	{
		// strdup each string of the env
		copy[i] = ft_strdup(envp[i]);
		if (!copy[i]) // small check
			return (free_env(copy), NULL);
		i++;
	}
	// last line in env is NULL
	copy[i] = NULL;
	// return the copied env
	return (copy);
}

// free each string of an environment
void	free_env(char **envp)
{
	int	i;

	if (!envp)
		return ;
	i = 0;
	while (envp[i])
		free(envp[i++]);
	free(envp);
}

// returns a pointer to the value 
// part of a variable after the '='
char	*env_get(char **envp, char *key)
{
	int	i;
	int	len;

	i = 0;
	// get the lenght of the key
	len = ft_strlen(key);
	// loop over the environment
	while (envp && envp[i])
	{
		// if the key is found and next to it a '=' then return it
		if (!ft_strncmp(envp[i], key, len) && envp[i][len] == '=')
			return (envp[i] + len + 1);
		i++;
	}
	return (NULL);
}

// either update an existing variable
// or call env_append to create a new one
int	env_set(t_shell *shell, char *entry)
{
	int	i;
	int	len;

	i = 0;
	// get the lenght of the key
	len = key_len(entry);
	// loop over the environment
	while (shell->envp && shell->envp[i])
	{
		// if the variable name already exits
		if (env_key_match(shell->envp[i], entry, len))
		{
			// if the new entry doesn't have a '=' , don't update
			if (!ft_strchr(entry, '='))
				return (0);
			// free the old "KEY=VALUE" and replace it with the new one
			return (free(shell->envp[i]), shell->envp[i] = ft_strdup(entry),
				shell->envp[i] == NULL);
		}
		i++;
	}
	// if we didn't find the key add it to the end
	return (env_append(shell, entry, i));
}

// removes a variable from the environment
int	env_unset(t_shell *shell, char *key)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	// get the lenght of the key
	len = ft_strlen(key);
	while (shell->envp && shell->envp[i])
	{
		// if the key is found
		if (env_key_match(shell->envp[i], key, len))
		{
			// delete the string
			free(shell->envp[i]);
			j = i; // flag
			// shift all following pointers to 
			// one slot to the left to close the gap
			while (shell->envp[j + 1])
			{
				// current one = next one
				shell->envp[j] = shell->envp[j + 1];
				j++;
			}
			// mark the end of the array
			shell->envp[j] = NULL;
			return (0);
		}
		i++;
	}
	return (0);
}
