#include "../minishell.h"

int	ft_pwd(void)
{
	char	buffer[4096];

	if (!getcwd(buffer, sizeof(buffer)))
	{
		perror("minishell: pwd");
		return (1);
	}
	ft_putstr(1, buffer);
	ft_putstr(1, "\n");
	return (0);
}
