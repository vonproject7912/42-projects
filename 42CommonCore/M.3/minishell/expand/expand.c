/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vonpr <vonpr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 12:22:09 by vonpr             #+#    #+#             */
/*   Updated: 2026/04/29 17:11:03 by vonpr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

char	*expand_var(int *i, char *str, char **env, t_shell *shell)
{
	char	*key;
	int		start;
	char	*value;

	(*i)++;
	if (str[*i] == '?')
	{
		(*i)++;
		return (ft_itoa(shell->last_exit));
	}
	if (!is_var_start(str[*i]))
		return (ft_strdup("$"));
	start = *i;
	while (str[*i] && is_var_char(str[*i]))
		(*i)++;
	key = ft_strndup(str + start, *i - start);
	if (!key)
		return (NULL);
	value = ft_strdup(get_env_value(key, env));
	free(key);
	return (value);
}

int	expand_str(char **str, int quote, char **env, int *last_exit)
{
	int		i;
	int		start;
	char	*value;
	char	*result;

	i = 0;
	value = NULL;
	result = NULL;
	if (!str || !*str || quote == 1)
		return (0);
	if ((*str)[0] == '\0')
		return (0);
	while ((*str)[i])
	{
		start = i;
		while ((*str)[i] && (*str)[i] != '$')
			i++;
		result = append_part(result, ft_strndup((*str) + start, i - start));
		if (!result)
			return (1);
		if ((*str)[i] == '$')
		{
			value = expand_var(&i, *str, env, last_exit);
			result = append_part(result, value);
			if (!result)
				return (1);
		}
	}
	free(*str);
	*str = result;
	return (0);
}

int	expand_cmd(t_cmd *commands, char **env, int *last_exit)
{
	int		i;
	t_cmd	*current;
	t_redir	*current_redir;

	current = commands;
	while (current)
	{
		i = 0;
		while (current->argv && current->argv[i])
		{
			if (expand_str(&current->argv[i], current->quotes[i], env,
					last_exit))
				return (malloc_err(last_exit), 1);
			i++;
		}
		current_redir = current->redirs;
		while (current_redir)
		{
			if (current_redir->type != HEREDOC
				&& expand_str(&current_redir->file, current_redir->quote, env,
					last_exit))
				return (malloc_err(last_exit), 1);
			current_redir = current_redir->next;
		}
		current = current->next;
	}
	return (0);
}
