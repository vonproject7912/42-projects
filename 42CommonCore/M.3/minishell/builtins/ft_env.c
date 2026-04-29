#include "../minishell.h"

int	ft_env(t_shell *shell, t_cmd *cmd)
{
	int	i;

	if (cmd->argv[1])
	{
		ft_putstr(2, "minishell: env: no options or arguments supported\n");
		return (1);
	}
	i = 0;
	while (shell->envp && shell->envp[i])
	{
		if (ft_strchr(shell->envp[i], '='))
		{
			ft_putstr(1, shell->envp[i]);
			ft_putstr(1, "\n");
		}
		i++;
	}
	return (0);
}
