/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vonpr <vonpr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 09:52:22 by vonpr             #+#    #+#             */
/*   Updated: 2026/05/01 15:33:23 by vonpr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// simple helper to count how
// many env variables there are
static int	env_count_local(char **envp)
{
	int	count;

	count = 0;
	while (envp && envp[count])
		count++;
	return (count);
}

// create a copy of the environment 
// we only copy the pointers (the addresses) NOT the actual strings
static char	**copy_env_ptrs(char **envp)
{
	char	**copy;
	int		i;

	copy = malloc(sizeof(char *) * (env_count_local(envp) + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (envp && envp[i])
	{
		copy[i] = envp[i]; // just copy the adress
		i++;
	}
	copy[i] = NULL;
	return (copy);
}

// standard Bubble sort for the expand
static void	sort_env(char **envp)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	while (envp && envp[i])
	{
		j = i + 1;
		while (envp[j])
		{
			// compares the current line witht the next one
			if (ft_strcmp(envp[i], envp[j]) > 0)
			{
				// swap the pointers
				tmp = envp[i];
				envp[i] = envp[j];
				envp[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

// when export is called alone
static int	print_sorted_export(char **envp)
{
	char	**copy;

	// copy the env pointers
	copy = copy_env_ptrs(envp);
	if (!copy) // small check
		return (1);
	// sort everything
	sort_env(copy);
	// print everything
	print_export(copy);
	// free the copy we made
	free(copy);
	return (0);
}

// the implementation of the export builtin
int	ft_export(t_shell *shell, t_cmd *cmd)
{
	int	i;
	int	status;

	// if 'export' has no arguments
	if (!cmd->argv[1]) // print the sorted env
		return (print_sorted_export(shell->envp));
	i = 1;
	status = 0;
	// loop through each argument: 'export VAR1=val VAR2=val'
	while (cmd->argv[i])
	{
		// call the function to ensure the name is valid
		if (!is_valid_identifier(cmd->argv[i]))
		{
			ft_putstr(2, "minishell: export: not a valid identifier\n");
			status = 1;
		}
		// if valid use env_set function that either add/update the array
		else if (env_set(shell, cmd->argv[i]))
			status = 1;
		i++;
	}
	return (status);
}
