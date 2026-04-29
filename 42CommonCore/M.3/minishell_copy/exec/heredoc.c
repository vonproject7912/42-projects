#include "../minishell.h"

static void	heredoc_child(char *delimiter, int pipe_fd[2])
{
	char	*line;

	setup_child_exec_signals();
	close(pipe_fd[0]);
	while (1)
	{
		line = readline("> ");
		if (!line)
			break ;
		if (!ft_strcmp(line, delimiter))
		{
			free(line);
			break ;
		}
		ft_putstr(pipe_fd[1], line);
		ft_putstr(pipe_fd[1], "\n");
		free(line);
	}
	close(pipe_fd[1]);
	exit(0);
}

int	open_heredoc(char *delimiter)
{
	int		pipe_fd[2];
	int		status;
	pid_t	pid;

	if (pipe(pipe_fd) < 0)
		return (perror("minishell: pipe"), -1);
	pid = fork();
	if (pid < 0)
	{
		close(pipe_fd[0]);
		close(pipe_fd[1]);
		return (perror("minishell: fork"), -1);
	}
	if (pid == 0)
		heredoc_child(delimiter, pipe_fd);
	setup_parent_exec_signals();
	close(pipe_fd[1]);
	waitpid(pid, &status, 0);
	setup_prompt_signals();
	if (WIFSIGNALED(status))
		return (close(pipe_fd[0]), -2);
	if (WIFEXITED(status) && WEXITSTATUS(status) != 0)
		return (close(pipe_fd[0]), WEXITSTATUS(status));
	return (pipe_fd[0]);
}
