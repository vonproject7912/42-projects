#include "../minishell.h"

static int	ms_is_blank(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '\t')
			return (0);
		i++;
	}
	return (1);
}

static int	ms_read_line(char **line)
{
	*line = readline("minishell$ ");
	if (!*line)
	{
		ft_putstr(1, "exit\n");
		return (0);
	}
	if ((*line)[0])
		add_history(*line);
	return (1);
}

static void	ms_exec_line(char *line, t_shell *shell)
{
	t_token	*tokens;
	t_cmd	*commands;
	int		parse_status;

	if (ms_is_blank(line))
		return ;
	parse_status = 0;
	tokens = lexer(&parse_status, line);
	if (!tokens)
	{
		if (parse_status)
			shell->last_exit = parse_status;
		return ;
	}
	commands = parse(&parse_status, &tokens);
	if (!commands)
	{
		if (parse_status)
			shell->last_exit = parse_status;
		return ;
	}
	if (expand_cmd(commands, shell->envp, &shell->last_exit))
	{
		free_commands(&commands);
		return ;
	}
	shell->last_exit = run_commands(commands, shell);
	free_commands(&commands);
}

static void	update_signal_status(t_shell *shell)
{
	if (g_signal)
	{
		shell->last_exit = g_signal;
		g_signal = 0;
	}
}

int	shell_loop(char **envp)
{
	char	*line;
	t_shell	shell;

	shell.envp = env_dup(envp);
	if (!shell.envp)
		return (1);
	shell.last_exit = 0;
	shell.should_exit = 0;
	setup_prompt_signals();
	while (!shell.should_exit)
	{
		if (!ms_read_line(&line))
			break ;
		update_signal_status(&shell);
		ms_exec_line(line, &shell);
		free(line);
	}
	rl_clear_history();
	free_env(shell.envp);
	return (shell.last_exit);
}
