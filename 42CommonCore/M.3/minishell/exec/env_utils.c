/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vonpr <vonpr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 08:18:49 by vonpr             #+#    #+#             */
/*   Updated: 2026/05/01 08:24:28 by vonpr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	env_count(char **envp)
{
	int	count;

	count = 0;
	while (envp && envp[count])
		count++;
	return (count);
}

int	key_len(char *entry)
{
	int	i;

	i = 0;
	while (entry[i] && entry[i] != '=')
		i++;
	return (i);
}

int	env_key_match(char *entry, char *key, int len)
{
	return (!ft_strncmp(entry, key, len)
		&& (entry[len] == '=' || entry[len] == '\0'));
}

int	env_append(t_shell *shell, char *entry, int count)
{
	char	**new_env;
	int		i;

	new_env = malloc(sizeof(char *) * (count + 2));
	if (!new_env)
		return (1);
	i = -1;
	while (shell->envp && shell->envp[++i])
		new_env[i] = shell->envp[i];
	if (i < 0)
		i = 0;
	new_env[i] = ft_strdup(entry);
	new_env[i + 1] = NULL;
	free(shell->envp);
	shell->envp = new_env;
	return (new_env[i] == NULL);
}
