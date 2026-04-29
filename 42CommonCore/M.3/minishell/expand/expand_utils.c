/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vonpr <vonpr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 12:22:46 by vonpr             #+#    #+#             */
/*   Updated: 2026/04/29 20:32:11 by vonpr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_var_start(char c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || c == '_')
		return (1);
	return (0);
}

int	is_var_char(char c)
{
	if (is_var_start(c) || (c >= '0' && c <= '9'))
		return (1);
	return (0);
}

char	*append_part(char *result, char *part)
{
	char	*new_result;

	if (!part)
		return (free(result), NULL);
	new_result = ft_strjoin(result, part);
	free(result);
	free(part);
	return (new_result);
}

char	*get_env_value(char *key, char **env)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(key);
	while (env && env[i])
	{
		if (!ft_strncmp(env[i], key, len) && env[i][len] == '=')
			return (env[i] + len + 1);
		i++;
	}
	return ("");
}
