/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vonpr <vonpr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 08:19:45 by vonpr             #+#    #+#             */
/*   Updated: 2026/05/01 08:24:24 by vonpr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**env_dup(char **envp)
{
	char	**copy;
	int		i;

	copy = malloc(sizeof(char *) * (env_count(envp) + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (envp && envp[i])
	{
		copy[i] = ft_strdup(envp[i]);
		if (!copy[i])
			return (free_env(copy), NULL);
		i++;
	}
	copy[i] = NULL;
	return (copy);
}

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

char	*env_get(char **envp, char *key)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(key);
	while (envp && envp[i])
	{
		if (!ft_strncmp(envp[i], key, len) && envp[i][len] == '=')
			return (envp[i] + len + 1);
		i++;
	}
	return (NULL);
}

int	env_set(t_shell *shell, char *entry)
{
	int	i;
	int	len;

	i = 0;
	len = key_len(entry);
	while (shell->envp && shell->envp[i])
	{
		if (env_key_match(shell->envp[i], entry, len))
		{
			if (!ft_strchr(entry, '='))
				return (0);
			return (free(shell->envp[i]), shell->envp[i] = ft_strdup(entry),
				shell->envp[i] == NULL);
		}
		i++;
	}
	return (env_append(shell, entry, i));
}

int	env_unset(t_shell *shell, char *key)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	len = ft_strlen(key);
	while (shell->envp && shell->envp[i])
	{
		if (env_key_match(shell->envp[i], key, len))
		{
			free(shell->envp[i]);
			j = i;
			while (shell->envp[j + 1])
			{
				shell->envp[j] = shell->envp[j + 1];
				j++;
			}
			shell->envp[j] = NULL;
			return (0);
		}
		i++;
	}
	return (0);
}
