/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vonpr <vonpr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 12:22:09 by vonpr             #+#    #+#             */
/*   Updated: 2026/05/01 11:44:09 by vonpr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// get the name and value of a single variable
char	*expand_var(int *i, char *str, char **env, t_shell *shell)
{
	char	*key;
	int		start;
	char	*value;

	(*i)++; // skip $
	// Handle the $? case
	if (str[*i] == '?')
	{
		(*i)++; // pass $
		// the value to print is the last_exit
		return (ft_itoa(shell->last_exit));
	}
	// check if there are invalid char
	// treat as litteral $
	if (!is_var_start(str[*i]))
		return (ft_strdup("$"));
	start = *i; // get the start of the variable
	while (str[*i] && is_var_char(str[*i]))
		(*i)++; // move to the end
	// copie the actual variable name
	key = ft_strndup(str + start, *i - start);
	if (!key) // small check
		return (NULL);
	// get the value of the variable
	value = ft_strdup(get_env_value(key, env));
	// free the variable's name
	free(key);
	// return the value of the variable
	return (value);
}

// iterate through each string replacing all $VAR by their actual value
int	expand_str(char **str, int quote, char **env, t_shell *shell)
{
	int		i;
	int		start;
	char	*result;

	i = 0;
	result = NULL;
	// Single quote case + small check
	if (!str || !*str || quote == 1)
		return (0);
	// if the string is empty return
	if ((*str)[0] == '\0')
		return (0);
	// loop through the whole string
	while ((*str)[i])
	{
		// get the start
		start = i;
		// move until a $ is found
		while ((*str)[i] && (*str)[i] != '$')
			i++;
		// append the litteral text found before the $
		result = append_part(result, ft_strndup((*str) + start, i - start));
		// replace the variable by it's actual value
		if ((*str)[i] == '$')
			result = append_part(result, expand_var(&i, *str, env, shell));
		// small check
		if (!result)
			return (1);
	}
	// free my old unexpanded string
	free(*str);
	// change to the new expanded string
	*str = result;
	return (0);
}

// helper function to expand_cmd and handles redirections
static int	expand_redir(t_redir *redir, char **env, t_shell *shell)
{
	// loop throught the whole linked list of one command
	while (redir)
	{
		// ignore heredo redirection
		if (redir->type != HEREDOC && expand_str(&redir->file, redir->quote,
				env, shell))
			return (1);
		redir = redir->next;
	}
	return (0);
}

// loop through each argv looking for potential expansion
int	expand_cmd(t_cmd *commands, char **env, t_shell *shell)
{
	int		i;
	t_cmd	*current;

	current = commands;
	while (current)
	{
		i = 0;
		// expand variables for each argv of a command
		while (current->argv && current->argv[i])
		{
			if (expand_str(&current->argv[i], current->quotes[i], env, shell))
				return (malloc_err(shell), 1);
			i++;
		}
		// expand variables in redirection file for a command
		if (expand_redir(current->redirs, env, shell))
			return (malloc_err(shell), 1);
		current = current->next;
	}
	return (0);
}
