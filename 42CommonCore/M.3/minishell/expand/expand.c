/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vonpr <vonpr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 12:22:09 by vonpr             #+#    #+#             */
/*   Updated: 2026/04/29 20:29:06 by vonpr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

int	expand_str(char **str, int quote, char **env, t_shell *shell)
{
	int		i;
	int		start;
	char	*result;

	i = 0;
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
		if ((*str)[i] == '$')
			result = append_part(result, expand_var(&i, *str, env, shell));
		if (!result)
			return (1);
	}
	free(*str);
	*str = result;
	return (0);
}

static int	expand_redir(t_redir *redir, char **env, t_shell *shell)
{
	while (redir)
	{
		if (redir->type != HEREDOC && expand_str(&redir->file, redir->quote,
				env, shell))
			return (1);
		redir = redir->next;
	}
	return (0);
}

int	expand_cmd(t_cmd *commands, char **env, t_shell *shell)
{
	int		i;
	t_cmd	*current;

	current = commands;
	while (current)
	{
		i = 0;
		while (current->argv && current->argv[i])
		{
			if (expand_str(&current->argv[i], current->quotes[i], env, shell))
				return (malloc_err(shell), 1);
			i++;
		}
		if (expand_redir(current->redirs, env, shell))
			return (malloc_err(shell), 1);
		current = current->next;
	}
	return (0);
}
