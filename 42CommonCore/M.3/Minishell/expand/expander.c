/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vonpr <vonpr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 17:36:25 by vonpr             #+#    #+#             */
/*   Updated: 2026/04/25 14:53:52 by vonpr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// — walks env array, finds KEY=value, returns value part
char *get_env_value(char *key, char **env)
{
    
}

// — finds $VAR or $?, looks up value, returns expanded string
char *expand_var(int *i, char *str, char **env, int *last_exit)
{
	int len;
	char *key;
    char *value;

	while (str[(*i)])
	{
		if (str[(*i)] == '$')
		{
			(*i)++;
			if (str[(*i)] == '?')
				return (ft_itoa(*last_exit)); // should code itoa
			len = (*i);
			while (str[len] && ft_isalnum(str[len])) // should code isalnum
				len++;
			key = ft_strndup(str + (*i), (len - (*i)));
			value = ft_strdup(get_env_value(key, env));
			free(key);
			(*i) = len;
			return (value);
		}
		(*i)++;
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
	value = NULL;
	result = NULL;
	while ((*str)[i])
	{
		len = i;
		while ((*str)[len] && (*str)[len] != '$')
			len++;
		result = ft_strjoin(result, ft_strndup((*str) + i, (len - i)));
		if (!result)
			return(1);
		i = len;
		if ((*str)[i] && (*str)[i] == '$')
		{
			value = expand_var(&i, (*str), env, last_exit);
			result = ft_strjoin(result, value);
			if (!result)
				return(1);
		}
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
			if (expand_str(&current->argv[i], current->quotes[i], env, last_exit))
				return (malloc_err(last_exit), 1);
			i++;
		}
		current_redir = current->redirs;
		while (current_redir)
		{
			if (expand_str(&current_redir->file, current_redir->quote, env, last_exit))
				return (malloc_err(last_exit), 1);
			current_redir = current_redir->next;
		}
		current = current->next;
	}
	return (0);
}
