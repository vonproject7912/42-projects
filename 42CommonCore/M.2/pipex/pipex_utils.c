/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vonpr <vonpr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 19:09:59 by vonpr             #+#    #+#             */
/*   Updated: 2026/04/10 15:56:13 by vonpr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// handles errors for the 2nd command
void	full_error_cmd2(char *mess, t_pipex *folder)
{
	perror(mess);
	safe_closing(folder->infile);
	safe_closing(folder->outfile);
	free(folder);
	exit(127);
}

// searches the environment variables to find the absolute path of a command
char	*find_path(char **cmd, char **envp)
{
	int		i;
	char	*tmp;
	char	**path;
	char	*full_path;

	i = 0;
	// check if the command is already a path
	if (cmd[0] && cmd[0][0] == '/' && (access(cmd[0], F_OK | X_OK) == 0))
		return (ft_strdup(cmd[0]));
	// search for the "PATH=" line in environment variables
	while (envp[i] && ft_strncmp(envp[i], "PATH=", 5) != 0)
		i++;
	// small checks
	if (!cmd || !cmd[0] || !envp[i])
		return (NULL);
	// split the PATH variable into individual directories
	path = ft_split(envp[i] + 5, ':');
	i = 0;
	// build the path
	while (path[i])
	{
		// appending the command to each directory
		tmp = ft_strjoin(path[i], "/");
		full_path = ft_strjoin(tmp, cmd[0]);
		free(tmp);
		// check if the file exists and is executable
		if (access(full_path, F_OK | X_OK) == 0)
			return (free_tab(path), full_path); // sucess
		free(full_path);
		i++;
	}
	return (free_tab(path), NULL); // failure
}

// execute the first command
void	exec_enfant_1(char *cmd, char **envp, t_pipex *folder)
{
	char	*path;
	char	**arg;

	arg = ft_split(cmd, ' ');
	// check
	if (!arg || !arg[0])
		full_error("argument issue", folder);
	// find the path to the command
	path = find_path(arg, envp);
	// check
	if (!path)
	{
		free_tab(arg);
		full_error("No path", folder);
	}
	// replaces the process with execve
	if (execve(path, arg, envp) == -1)
	{
		free(path);
		free_tab(arg);
		write(2, "Execution issue", 16);
		exit(0);
	}
}

// same executing process for the second command
void	exec_enfant_2(char *cmd, char **envp, t_pipex *folder)
{
	char	*path;
	char	**arg;

	arg = ft_split(cmd, ' ');
	if (!arg || !arg[0])
		full_error_cmd2("argument issue", folder);
	path = find_path(arg, envp);
	if (!path)
	{
		free_tab(arg);
		full_error_cmd2("No path", folder);
	}
	if (execve(path, arg, envp) == -1)
	{
		free(path);
		free_tab(arg);
		full_error_cmd2("Execution issue", folder);
	}
}

/* Path example:
PATH=/usr/bin:/bin:/usr/sbin

It tries: /usr/bin/ + ls -> Check Access
If not found, it tries: /bin/ + ls -> Check Access
If not found, it tries: /usr/sbin/ + ls -> Check Access
*/