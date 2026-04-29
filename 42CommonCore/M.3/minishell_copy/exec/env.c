#include "../minishell.h"

static int	env_count(char **envp)
{
	int	count;

	count = 0;
	while (envp && envp[count])
		count++;
	return (count);
}

static int	key_len(char *entry)
{
	int	i;

	i = 0;
	while (entry[i] && entry[i] != '=')
		i++;
	return (i);
}

static int	env_key_match(char *entry, char *key, int len)
{
	return (!ft_strncmp(entry, key, len)
		&& (entry[len] == '=' || entry[len] == '\0'));
}

char	**env_dup(char **envp)
{
	char	**copy;
	int		i;

	copy = malloc(sizeof(char *) * (env_count(envp) + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (envp && envp[i])
	{
		copy[i] = ft_strdup(envp[i]);
		if (!copy[i])
			return (free_env(copy), NULL);
		i++;
	}
	copy[i] = NULL;
	return (copy);
}

void	free_env(char **envp)
{
	int	i;

	if (!envp)
		return ;
	i = 0;
	while (envp[i])
		free(envp[i++]);
	free(envp);
}

char	*env_get(char **envp, char *key)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(key);
	while (envp && envp[i])
	{
		if (!ft_strncmp(envp[i], key, len) && envp[i][len] == '=')
			return (envp[i] + len + 1);
		i++;
	}
	return (NULL);
}

int	env_set(t_shell *shell, char *entry)
{
	char	**new_env;
	int		i;
	int		len;

	i = 0;
	len = key_len(entry);
	while (shell->envp && shell->envp[i])
	{
		if (env_key_match(shell->envp[i], entry, len))
		{
			if (!ft_strchr(entry, '='))
				return (0);
			return (free(shell->envp[i]), shell->envp[i] = ft_strdup(entry),
				shell->envp[i] == NULL);
		}
		i++;
	}
	new_env = malloc(sizeof(char *) * (i + 2));
	if (!new_env)
		return (1);
	i = -1;
	while (shell->envp && shell->envp[++i])
		new_env[i] = shell->envp[i];
	if (i < 0)
		i = 0;
	new_env[i] = ft_strdup(entry);
	new_env[i + 1] = NULL;
	free(shell->envp);
	shell->envp = new_env;
	return (new_env[i] == NULL);
}

int	env_unset(t_shell *shell, char *key)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	len = ft_strlen(key);
	while (shell->envp && shell->envp[i])
	{
		if (env_key_match(shell->envp[i], key, len))
		{
			free(shell->envp[i]);
			j = i;
			while (shell->envp[j + 1])
			{
				shell->envp[j] = shell->envp[j + 1];
				j++;
			}
			shell->envp[j] = NULL;
			return (0);
		}
		i++;
	}
	return (0);
}
