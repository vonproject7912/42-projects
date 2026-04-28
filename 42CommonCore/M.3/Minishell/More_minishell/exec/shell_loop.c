#include "minishell.h"
#include <readline/readline.h>
#include <readline/history.h>

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
		write(1, "exit\n", 5);
		return (0);
	}
	if ((*line)[0])
		add_history(*line);
	return (1);
}

static void	ms_exec_line(char *line, char **envp, int *last_exit)
{
	t_token	*tokens;

	if (ms_is_blank(line))
		return ;
	tokens = lexer(line, last_exit);
	if (!tokens)
		return ;
	*last_exit = run_command(tokens, envp);
	free_tokens(tokens);
}

int	shell_loop(char **envp)
{
	char	*line;
	int		last_exit;

	last_exit = 0;
	while (1)
	{
		if (!ms_read_line(&line))
			break ;
		ms_exec_line(line, envp, &last_exit);
		free(line);
	}
	rl_clear_history();
	return (last_exit);
}
