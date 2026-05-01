/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vonpr <vonpr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 09:35:10 by vonpr             #+#    #+#             */
/*   Updated: 2026/05/01 09:37:26 by vonpr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	run_parent_builtin(t_cmd *cmd, t_shell *shell)
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

int	spawn_cmd(t_cmd *cmd, t_shell *shell, int in_fd, int pipe_fd[2])
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

static int	run_pipeline(t_cmd *commands, t_shell *shell, pid_t *last_pid)
{
	t_cmd	*cmd;
	int		in_fd;
	int		pipe_fd[2];

	cmd = commands;
	in_fd = STDIN_FILENO;
	setup_parent_exec_signals();
	while (cmd)
	{
		if (cmd->next && pipe(pipe_fd) < 0)
			return (perror("minishell: pipe"), 1);
		*last_pid = spawn_cmd(cmd, shell, in_fd, pipe_fd);
		if (in_fd != STDIN_FILENO)
			close(in_fd);
		if (cmd->next)
			close(pipe_fd[1]);
		in_fd = STDIN_FILENO;
		if (cmd->next)
			in_fd = pipe_fd[0];
		cmd = cmd->next;
	}
	return (0);
}

static void	wait_pipeline(t_shell *shell, pid_t last_pid)
{
	pid_t	wait_pid;
	int		status;

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
}

int	run_commands(t_cmd *commands, t_shell *shell)
{
	pid_t	last_pid;
	int		status;

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
	last_pid = 0;
	if (run_pipeline(commands, shell, &last_pid))
		return (1);
	wait_pipeline(shell, last_pid);
	setup_prompt_signals();
	return (shell->last_exit);
}
