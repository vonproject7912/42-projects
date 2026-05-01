/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_one.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vonpr <vonpr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 09:15:14 by vonpr             #+#    #+#             */
/*   Updated: 2026/05/01 09:29:41 by vonpr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_builtin(char *cmd)
{
	if (!cmd)
		return (0);
	return (!ft_strcmp(cmd, "echo") || !ft_strcmp(cmd, "cd") || !ft_strcmp(cmd,
			"pwd") || !ft_strcmp(cmd, "export") || !ft_strcmp(cmd, "unset")
		|| !ft_strcmp(cmd, "env") || !ft_strcmp(cmd, "exit"));
}

int	is_parent_builtin(char *cmd)
{
	if (!cmd)
		return (0);
	return (!ft_strcmp(cmd, "cd") || !ft_strcmp(cmd, "export")
		|| !ft_strcmp(cmd, "unset") || !ft_strcmp(cmd, "exit"));
}

int	run_builtin(t_shell *shell, t_cmd *cmd)
{
	if (!cmd->argv || !cmd->argv[0])
		return (0);
	if (!ft_strcmp(cmd->argv[0], "echo"))
		return (ft_echo(cmd));
	if (!ft_strcmp(cmd->argv[0], "cd"))
		return (ft_cd(shell, cmd));
	if (!ft_strcmp(cmd->argv[0], "pwd"))
		return (ft_pwd());
	if (!ft_strcmp(cmd->argv[0], "export"))
		return (ft_export(shell, cmd));
	if (!ft_strcmp(cmd->argv[0], "unset"))
		return (ft_unset(shell, cmd));
	if (!ft_strcmp(cmd->argv[0], "env"))
		return (ft_env(shell, cmd));
	if (!ft_strcmp(cmd->argv[0], "exit"))
		return (ft_exit(shell, cmd));
	return (1);
}

char	*join_path(char *dir, char *cmd)
{
	char	*tmp;
	char	*path;

	tmp = ft_strjoin(dir, "/");
	if (!tmp)
		return (NULL);
	path = ft_strjoin(tmp, cmd);
	free(tmp);
	return (path);
}

char	*next_path_dir(char **path)
{
	char	*start;
	char	*dir;
	int		len;

	start = *path;
	len = 0;
	while (start[len] && start[len] != ':')
		len++;
	dir = ft_strndup(start, len);
	if (start[len] == ':')
		*path = start + len + 1;
	else
		*path = start + len;
	return (dir);
}
