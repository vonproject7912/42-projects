#include "../minishell.h"

static int	is_valid_identifier(char *str)
{
	int	i;

	if (!str || (!((str[0] >= 'A' && str[0] <= 'Z') || (str[0] >= 'a'
					&& str[0] <= 'z') || str[0] == '_')))
		return (0);
	i = 1;
	while (str[i])
	{
		if (!((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a'
					&& str[i] <= 'z') || (str[i] >= '0' && str[i] <= '9')
				|| str[i] == '_'))
			return (0);
		i++;
	}
	return (1);
}

int	ft_unset(t_shell *shell, t_cmd *cmd)
{
	int	i;
	int	status;

	i = 1;
	status = 0;
	while (cmd->argv[i])
	{
		if (!is_valid_identifier(cmd->argv[i]))
		{
			ft_putstr(2, "minishell: unset: not a valid identifier\n");
			status = 1;
		}
		else if (env_unset(shell, cmd->argv[i]))
			status = 1;
		i++;
	}
	return (status);
}
