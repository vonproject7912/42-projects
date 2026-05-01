/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_two.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vonpr <vonpr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 09:30:47 by vonpr             #+#    #+#             */
/*   Updated: 2026/05/01 09:34:11 by vonpr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*find_command_path(t_shell *shell, char *cmd)
{
	char	*path_env;
	char	*cursor;
	char	*dir;
	char	*path;

	if (ft_strchr(cmd, '/'))
		return (ft_strdup(cmd));
	path_env = env_get(shell->envp, "PATH");
	if (!path_env)
		return (NULL);
	cursor = path_env;
	while (*cursor)
	{
		dir = next_path_dir(&cursor);
		path = join_path(dir, cmd);
		free(dir);
		if (path && access(path, X_OK) == 0)
			return (path);
		free(path);
	}
	return (NULL);
}

static int	open_redir_fd(t_redir *redir)
{
	if (redir->type == REDIR_IN)
		return (open(redir->file, O_RDONLY));
	else if (redir->type == REDIR_OUT)
		return (open(redir->file, O_CREAT | O_WRONLY | O_TRUNC, 0644));
	else if (redir->type == REDIR_APPEND)
		return (open(redir->file, O_CREAT | O_WRONLY | O_APPEND, 0644));
	else if (redir->type == HEREDOC)
		return (redir->heredoc_fd);
	return (-1);
}

int	apply_redirs(t_redir *redir)
{
	int	fd;

	while (redir)
	{
		fd = open_redir_fd(redir);
		if (fd < 0)
			return (perror(redir->file), 1);
		if ((redir->type == REDIR_IN && dup2(fd, STDIN_FILENO) < 0)
			|| (redir->type == HEREDOC && dup2(fd, STDIN_FILENO) < 0)
			|| (redir->type != REDIR_IN && redir->type != HEREDOC && dup2(fd,
					STDOUT_FILENO) < 0))
			return (close(fd), perror("minishell: dup2"), 1);
		close(fd);
		if (redir->type == HEREDOC)
			redir->heredoc_fd = -1;
		redir = redir->next;
	}
	return (0);
}

int	prepare_heredocs(t_cmd *commands)
{
	t_cmd	*cmd;
	t_redir	*redir;
	int		fd;

	cmd = commands;
	while (cmd)
	{
		redir = cmd->redirs;
		while (redir)
		{
			if (redir->type == HEREDOC)
			{
				fd = open_heredoc(redir->file);
				if (fd == -2)
					return (130);
				if (fd < 0)
					return (1);
				redir->heredoc_fd = fd;
			}
			redir = redir->next;
		}
		cmd = cmd->next;
	}
	return (0);
}

void	exec_child(t_cmd *cmd, t_shell *shell)
{
	char	*path;
	int		status;

	status = apply_redirs(cmd->redirs);
	if (status)
		exit(status);
	if (!cmd->argv || !cmd->argv[0])
		exit(0);
	if (is_builtin(cmd->argv[0]))
		exit(run_builtin(shell, cmd));
	path = find_command_path(shell, cmd->argv[0]);
	if (!path)
	{
		ft_putstr(2, "minishell: command not found: ");
		ft_putstr(2, cmd->argv[0]);
		ft_putstr(2, "\n");
		exit(127);
	}
	execve(path, cmd->argv, shell->envp);
	perror(cmd->argv[0]);
	free(path);
	exit(126);
}
