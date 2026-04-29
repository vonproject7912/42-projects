#include "../minishell.h"

static int	is_valid_identifier(char *str)
{
	int	i;

	if (!str || (!((str[0] >= 'A' && str[0] <= 'Z') || (str[0] >= 'a'
					&& str[0] <= 'z') || str[0] == '_')))
		return (0);
	i = 1;
	while (str[i] && str[i] != '=')
	{
		if (!((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a'
					&& str[i] <= 'z') || (str[i] >= '0' && str[i] <= '9')
				|| str[i] == '_'))
			return (0);
		i++;
	}
	return (1);
}

static void	print_export(char **envp)
{
	int		i;
	char	*equal;

	i = 0;
	while (envp && envp[i])
	{
		equal = ft_strchr(envp[i], '=');
		ft_putstr(1, "declare -x ");
		if (equal)
		{
			write(1, envp[i], equal - envp[i] + 1);
			ft_putstr(1, "\"");
			ft_putstr(1, equal + 1);
			ft_putstr(1, "\"");
		}
		else
			ft_putstr(1, envp[i]);
		ft_putstr(1, "\n");
		i++;
	}
}

static int	env_count_local(char **envp)
{
	int	count;

	count = 0;
	while (envp && envp[count])
		count++;
	return (count);
}

static char	**copy_env_ptrs(char **envp)
{
	char	**copy;
	int		i;

	copy = malloc(sizeof(char *) * (env_count_local(envp) + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (envp && envp[i])
	{
		copy[i] = envp[i];
		i++;
	}
	copy[i] = NULL;
	return (copy);
}

static void	sort_env(char **envp)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	while (envp && envp[i])
	{
		j = i + 1;
		while (envp[j])
		{
			if (ft_strcmp(envp[i], envp[j]) > 0)
			{
				tmp = envp[i];
				envp[i] = envp[j];
				envp[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

static int	print_sorted_export(char **envp)
{
	char	**copy;

	copy = copy_env_ptrs(envp);
	if (!copy)
		return (1);
	sort_env(copy);
	print_export(copy);
	free(copy);
	return (0);
}

int	ft_export(t_shell *shell, t_cmd *cmd)
{
	int	i;
	int	status;

	if (!cmd->argv[1])
		return (print_sorted_export(shell->envp));
	i = 1;
	status = 0;
	while (cmd->argv[i])
	{
		if (!is_valid_identifier(cmd->argv[i]))
		{
			ft_putstr(2, "minishell: export: not a valid identifier\n");
			status = 1;
		}
		else if (env_set(shell, cmd->argv[i]))
			status = 1;
		i++;
	}
	return (status);
}
