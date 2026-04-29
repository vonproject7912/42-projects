#include "../minishell.h"

int	is_builtin(char *cmd)
{
	if (!cmd)
		return (0);
	return (!ft_strcmp(cmd, "echo") || !ft_strcmp(cmd, "cd")
		|| !ft_strcmp(cmd, "pwd") || !ft_strcmp(cmd, "export")
		|| !ft_strcmp(cmd, "unset") || !ft_strcmp(cmd, "env")
		|| !ft_strcmp(cmd, "exit"));
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

static char	*join_path(char *dir, char *cmd)
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

static char	*next_path_dir(char **path)
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

static char	*find_command_path(t_shell *shell, char *cmd)
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

static int	apply_redirs(t_redir *redir)
{
	int	fd;

	while (redir)
	{
		if (redir->type == REDIR_IN)
			fd = open(redir->file, O_RDONLY);
		else if (redir->type == REDIR_OUT)
			fd = open(redir->file, O_CREAT | O_WRONLY | O_TRUNC, 0644);
		else if (redir->type == REDIR_APPEND)
			fd = open(redir->file, O_CREAT | O_WRONLY | O_APPEND, 0644);
		else if (redir->type == HEREDOC)
			fd = redir->heredoc_fd;
		else
			fd = -1;
		if (fd < 0)
			return (perror(redir->file), 1);
		if ((redir->type == REDIR_IN && dup2(fd, STDIN_FILENO) < 0)
			|| (redir->type == HEREDOC && dup2(fd, STDIN_FILENO) < 0)
			|| (redir->type != REDIR_IN && redir->type != HEREDOC
				&& dup2(fd, STDOUT_FILENO) < 0))
			return (close(fd), perror("minishell: dup2"), 1);
		close(fd);
		if (redir->type == HEREDOC)
			redir->heredoc_fd = -1;
		redir = redir->next;
	}
	return (0);
}

static int	prepare_heredocs(t_cmd *commands)
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

static void	exec_child(t_cmd *cmd, t_shell *shell)
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

static int	run_parent_builtin(t_cmd *cmd, t_shell *shell)
{
	int	stdin_save;
	int	stdout_save;
	int	status;

	stdin_save = dup(STDIN_FILENO);
	stdout_save = dup(STDOUT_FILENO);
	if (stdin_save < 0 || stdout_save < 0)
		return (perror("minishell: dup"), 1);
	if (apply_redirs(cmd->redirs))
		status = 1;
	else
		status = run_builtin(shell, cmd);
	dup2(stdin_save, STDIN_FILENO);
	dup2(stdout_save, STDOUT_FILENO);
	close(stdin_save);
	close(stdout_save);
	return (status);
}

static int	spawn_cmd(t_cmd *cmd, t_shell *shell, int in_fd, int pipe_fd[2])
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
		return (perror("minishell: fork"), -1);
	if (pid == 0)
	{
		setup_child_exec_signals();
		if (in_fd != STDIN_FILENO)
			dup2(in_fd, STDIN_FILENO);
		if (cmd->next)
			dup2(pipe_fd[1], STDOUT_FILENO);
		if (in_fd != STDIN_FILENO)
			close(in_fd);
		if (cmd->next)
			close(pipe_fd[0]);
		if (cmd->next)
			close(pipe_fd[1]);
		exec_child(cmd, shell);
	}
	return (pid);
}

int	run_commands(t_cmd *commands, t_shell *shell)
{
	t_cmd	*cmd;
	int		in_fd;
	int		pipe_fd[2];
	int		status;
	pid_t	wait_pid;
	pid_t	last_pid;

	if (commands && !commands->next && commands->argv && commands->argv[0]
		&& is_parent_builtin(commands->argv[0]))
	{
		status = prepare_heredocs(commands);
		if (status)
			return (status);
		return (run_parent_builtin(commands, shell));
	}
	status = prepare_heredocs(commands);
	if (status)
		return (status);
	cmd = commands;
	in_fd = STDIN_FILENO;
	last_pid = 0;
	setup_parent_exec_signals();
	while (cmd)
	{
		if (cmd->next && pipe(pipe_fd) < 0)
			return (perror("minishell: pipe"), 1);
		last_pid = spawn_cmd(cmd, shell, in_fd, pipe_fd);
		if (in_fd != STDIN_FILENO)
			close(in_fd);
		if (cmd->next)
			close(pipe_fd[1]);
		in_fd = STDIN_FILENO;
		if (cmd->next)
			in_fd = pipe_fd[0];
		cmd = cmd->next;
	}
	while (1)
	{
		wait_pid = wait(&status);
		if (wait_pid <= 0)
			break ;
		if (wait_pid == last_pid && WIFEXITED(status))
			shell->last_exit = WEXITSTATUS(status);
		else if (wait_pid == last_pid && WIFSIGNALED(status))
		{
			shell->last_exit = 128 + WTERMSIG(status);
			if (WTERMSIG(status) == SIGINT)
				ft_putstr(1, "\n");
			else if (WTERMSIG(status) == SIGQUIT)
				ft_putstr(1, "Quit (core dumped)\n");
		}
	}
	setup_prompt_signals();
	return (shell->last_exit);
}
