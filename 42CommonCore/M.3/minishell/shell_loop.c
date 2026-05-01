/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_loop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vonpr <vonpr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 08:12:52 by vonpr             #+#    #+#             */
/*   Updated: 2026/05/01 08:12:53 by vonpr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ms_parse_and_expand(char *line, t_shell *shell, t_cmd **commands)
{
	t_token	*tokens;

	tokens = lexer(shell, line);
	if (!tokens)
		return (1);
	*commands = parse(shell, &tokens);
	if (!*commands)
		return (1);
	if (expand_cmd(*commands, shell->envp, shell))
	{
		free_commands(commands);
		return (1);
	}
	return (0);
}

static void	ms_exec_line(char *line, t_shell *shell)
{
	t_cmd	*commands;

	if (ms_is_blank(line))
		return ;
	if (ms_parse_and_expand(line, shell, &commands))
		return ;
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
