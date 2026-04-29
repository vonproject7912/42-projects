#include "minishell.h"

static int	ms_str_eq(char *a, char *b)    //comparer les deux string, si c'est meme commande utiliser builtin sinon return 0 utiliser execve
{
	int	i;

	if (!a || !b)
		return (0);
	i = 0;
	while (a[i] && b[i] && a[i] == b[i])
		i++;
	return (a[i] == '\0' && b[i] == '\0');
}

static int	count_words(t_token *tokens, char **argv)
{
	int	count;

	count = 0;
	while (tokens)
	{
		if (tokens->type == WORD && tokens->value)
			argv[count++] = tokens->value;
		tokens = tokens->next;
	}
	argv[count] = NULL;
	return (count);
}

static int	ms_exec(t_token *tokens, char **envp)
{
	char	*argv[256];
	pid_t	pid;
	int		status;

	count_words(tokens, argv);
	pid = fork();
	if (pid < 0)
		return (perror("minishell: fork"), 1);
	if (pid == 0)
		execve("/bin/ls", argv, envp);
	if (pid == 0)
		return (perror("minishell: execve"), exit(126), 126);
	waitpid(pid, &status, 0);
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	return (1);
}

int	run_command(t_token *tokens, char **envp)
{
	if (!tokens || tokens->type != WORD || !tokens->value)
		return (0);
	if (ms_str_eq(tokens->value, "ls"))
		return (ms_exec(tokens, envp));
	ft_putstr(2, "y'a que ls qui marche pour l'instant\n");
	return (127);
}
