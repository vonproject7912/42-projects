/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_loop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vonpr <vonpr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 08:12:52 by vonpr             #+#    #+#             */
/*   Updated: 2026/05/01 12:28:35 by vonpr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// prep: Lexing -> Parsing -> Expansion
static int	ms_parse_and_expand(char *line, t_shell *shell, t_cmd **commands)
{
	t_token	*tokens;

	// getting the tokens
	tokens = lexer(shell, line);
	if (!tokens) // small check
		return (1);
	// getting the commands
	*commands = parse(shell, &tokens);
	if (!*commands) // small check
		return (1);
	expand each commands
	if (expand_cmd(*commands, shell->envp, shell))
	{
		// if it failed (usually malloc fail here)
		free_commands(commands);
		return (1); // free + return
	}
	return (0);
}

// "exec": check for blank liines, parses, runs and cleans up
static void	ms_exec_line(char *line, t_shell *shell)
{
	t_cmd	*commands;

	// check for empty commands
	if (ms_is_blank(line))
		return ;
	// get the commands
	if (ms_parse_and_expand(line, shell, &commands))
		return ;
	// actually run the command in the "exec" folder
	shell->last_exit = run_commands(commands, shell);
	// free and clean up everything
	free_commands(&commands);
}

// sync the shell exit status with a signal
static void	update_signal_status(t_shell *shell)
{
	// using a global variable
	// which is a common practice
	if (g_signal) // for minishell
	{
		shell->last_exit = g_signal;
		g_signal = 0; // reset the signal 
		// after recording
	}
}

// the actual infinite loop 
// that keeps the shell running
int	shell_loop(char **envp)
{
	char	*line;
	t_shell	shell;

	// initialize and copy the system environment
	// into our own struct
	shell.envp = env_dup(envp);
	// small check 
	if (!shell.envp)
		return (1);
	// init the shell struct
	shell.last_exit = 0;
	shell.should_exit = 0;
	// set up the signal handlers for the 
	// interactive prompt
	setup_prompt_signals();
	// as long as shell_exit isn't set to 1
	while (!shell.should_exit)
	{
		// read the line
		if (!ms_read_line(&line))
			break ;
		// check for signal interrupts
		update_signal_status(&shell);
		// execute the line
		ms_exec_line(line, &shell);
		// free the line
		free(line);
	}
	// clean up everyting
	rl_clear_history();
	free_env(shell.envp);
	// return the last exit
	return (shell.last_exit);
}
