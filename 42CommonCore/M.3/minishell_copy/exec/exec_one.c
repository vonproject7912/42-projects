/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_one.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vonpr <vonpr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 09:15:14 by vonpr             #+#    #+#             */
/*   Updated: 2026/05/01 15:43:54 by vonpr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// check if a command matches any of the 7 mandatory builtins
int	is_builtin(char *cmd)
{
	if (!cmd)
		return (0);
	// compares the command string against our list of internal function
	return (!ft_strcmp(cmd, "echo") || !ft_strcmp(cmd, "cd") || !ft_strcmp(cmd,
			"pwd") || !ft_strcmp(cmd, "export") || !ft_strcmp(cmd, "unset")
		|| !ft_strcmp(cmd, "env") || !ft_strcmp(cmd, "exit"));
}

// checks if the command is a parent builtin
// crucial distinction: Parent builtins are commands that MUST run in the 
// main process because they modify the shell's state (PWD, Env, or exiting)
// commands like 'echo' can run in a child, but 'cd' cannot
int	is_parent_builtin(char *cmd)
{
	if (!cmd)
		return (0);
	// these 4 change the shell's internal memory/state
	return (!ft_strcmp(cmd, "cd") || !ft_strcmp(cmd, "export")
		|| !ft_strcmp(cmd, "unset") || !ft_strcmp(cmd, "exit"));
}

// call the specific builtin for each command
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

// simple path joining function
char	*join_path(char *dir, char *cmd)
{
	char	*tmp;
	char	*path;

	// join the diirectory and a '/'
	tmp = ft_strjoin(dir, "/");
	if (!tmp) // small check
		return (NULL);
	// join the rest
	path = ft_strjoin(tmp, cmd);
	free(tmp); // clean up
	return (path);
}

// function that extract one directory at a time looking for the ':'
// a PATH variable looks like: "/usr/bin:/bin:/usr/sbin"
char	*next_path_dir(char **path)
{
	char	*start;
	char	*dir;
	int		len;

	len = 0;
	start = *path; // save current position
	// count how many characters until the next ':' or end of string
	while (start[len] && start[len] != ':')
		len++;
	// creates a copy of just that directory name
	dir = ft_strndup(start, len);
	// update the pointer in the calling function
	// this moves the "bookmark" past the ':' so next 
	// time we get the NEXT folder
	if (start[len] == ':') // adavance the pointer + skips ':'
		*path = start + len + 1;
	else // otherwise just advance the pointer
		*path = start + len;
	return (dir);
}
