/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vonpr <vonpr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 11:05:10 by vonpr             #+#    #+#             */
/*   Updated: 2026/04/10 15:45:40 by vonpr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi_base(const char *str, int str_base)
{
	int	i;
	int	sign;
	int	digit;
	int	result;

	i = 0;
	result = 0;
	sign = 1;
	if (str_base < 2 || str_base > 16)
		return (0);
	// Gestion du signe
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	// Conversion
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			digit = str[i] - '0';
		else if (str[i] >= 'a' && str[i] <= 'f')
			digit = str[i] - 'a' + 10;
		else if (str[i] >= 'A' && str[i] <= 'F')
			digit = str[i] - 'A' + 10;
		// Valeur invalide pour arrêter
		else
			digit = str_base;
		// Arrêt si caractère invalide
		if (digit >= str_base)
			return (result * sign);
		result = result * str_base + digit;
		i++;
	}
	return (result * sign);
}

int	main(int ac, char **av)
{
	if (ac == 3)
		printf("%d", ft_atoi_base(av[1], atoi(av[2])));
	write(1, "\n", 1);
	return (0);
}
