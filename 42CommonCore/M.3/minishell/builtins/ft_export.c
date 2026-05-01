/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vonpr <vonpr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 09:52:22 by vonpr             #+#    #+#             */
/*   Updated: 2026/05/01 09:53:14 by vonpr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	env_count_local(char **envp)
{
	int	count;

	count = 0;
	while (envp && envp[count])
		count++;
	return (count);
}

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
		copy[i] = envp[i];
		i++;
	}
	copy[i] = NULL;
	return (copy);
}

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
			if (ft_strcmp(envp[i], envp[j]) > 0)
			{
				tmp = envp[i];
				envp[i] = envp[j];
				envp[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

static int	print_sorted_export(char **envp)
{
	char	**copy;

	copy = copy_env_ptrs(envp);
	if (!copy)
		return (1);
	sort_env(copy);
	print_export(copy);
	free(copy);
	return (0);
}

int	ft_export(t_shell *shell, t_cmd *cmd)
{
	int	i;
	int	status;

	if (!cmd->argv[1])
		return (print_sorted_export(shell->envp));
	i = 1;
	status = 0;
	while (cmd->argv[i])
	{
		if (!is_valid_identifier(cmd->argv[i]))
		{
			ft_putstr(2, "minishell: export: not a valid identifier\n");
			status = 1;
		}
		else if (env_set(shell, cmd->argv[i]))
			status = 1;
		i++;
	}
	return (status);
}
