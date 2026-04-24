/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vonpr <vonpr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 17:36:25 by vonpr             #+#    #+#             */
/*   Updated: 2026/04/24 12:28:56 by vonpr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// — walks env array, finds KEY=value, returns value part
char *get_env_value(char *key, char **env)
{
    
}

// — finds $VAR or $?, looks up value, returns expanded string
char *expand_var(char *str, char **env, int *last_exit)
{
	int i;
	int len;
	char *key;
    char *value;

	i = 0;
	while (str[i])
	{
		if (str[i] == '$')
		{
			i++;
			if (str[i] == '?')
				return (ft_itoa(*last_exit)); // should code itoa
			len = i;
			while (str[len] && ft_isalnum(str[len])) // should code isalnum
				len++;
			key = ft_strndup(str + i, (len - i));
			value = ft_strdup(get_env_value(key, env));
			free(key);
			return (value);
		}
		i++;
	}
	return (NULL);
}

// — expands a single string based on quote type, returns new string
int	expand_str(char **str, int quote, char **env, int *last_exit)
{
	int i;
	int len;
	char *value;
	char *result;

	i = 0;
    if (quote == 1)
		return (0);
	result = NULL;
	while ((*str)[i])
	{
		
	}
	free(*str);
	*str = result;
	if (value)
		free(value);
	return (0);
}

// — walks every command, calls expanders on each argv[i] and redir->file
int	expand_cmd(t_cmd *commands, char **env, int *last_exit)
{
	int i;
	t_cmd	*current;
	t_redir *current_redir;

	current = commands;
	while (current)
	{
		i = 0;
		while (current->argv[i])
		{
			if (expand_str(current->argv[i], current->quotes[i], env))
				return (malloc_err(last_exit), 1);
			i++;
		}
		current_redir = current->redirs;
		while (current_redir)
		{
			if (expand_str(current_redir->file, current_redir->quote, env))
				return (malloc_err(last_exit), 1);
			current_redir = current_redir->next;
		}
		current = current->next;
	}
	return (0);
}
