#include "../minishell.h"

static int	is_n_option(char *arg)
{
	int	i;

	if (!arg || arg[0] != '-' || arg[1] != 'n')
		return (0);
	i = 2;
	while (arg[i] == 'n')
		i++;
	return (arg[i] == '\0');
}

int	ft_echo(t_cmd *cmd)
{
	int	i;
	int	newline;

	i = 1;
	newline = 1;
	while (cmd->argv[i] && is_n_option(cmd->argv[i]))
	{
		newline = 0;
		i++;
	}
	while (cmd->argv[i])
	{
		ft_putstr(1, cmd->argv[i]);
		if (cmd->argv[i + 1])
			ft_putstr(1, " ");
		i++;
	}
	if (newline)
		ft_putstr(1, "\n");
	return (0);
}
