/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vonpr <vonpr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 01:27:35 by vonpr             #+#    #+#             */
/*   Updated: 2026/04/10 15:24:00 by vonpr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// extract from a starting point une sous-chaine
char	*ft_substr(char const *str, unsigned int start, size_t len)
{
	size_t	i;
	char	*sub;
	size_t	str_len;

	i = 0;
	if (!str)
		return (NULL);
	str_len = ft_strlen(str);
	if (start >= str_len)
		return (ft_strdup(""));
	if (len > str_len - start)
		len = str_len - start;
	sub = malloc(sizeof(char) * (len + 1));
	if (!sub)
		return (NULL);
	while (len > 0 && start < str_len)
	{
		sub[i] = str[start];
		len--;
		start++;
		i++;
	}
	sub[i] = '\0';
	return (sub);
}

/*First condition:
It caps len to the actual remaining characters in the string.
Example: str = "hello", start = 3, len = 10 → only 2 chars remain
("lo"), so len gets set to 2. Without it,
	you'd malloc too much and copy garbage.
Second condition:
len > 0 — stop when you've copied enough characters.
start < str_len — don't read past the string's end.
*/