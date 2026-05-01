/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vonpr <vonpr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 08:13:33 by vonpr             #+#    #+#             */
/*   Updated: 2026/05/01 08:13:33 by vonpr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// ignore argv argc and starts the loop
int	main(int argc, char **argv, char **envp)
{
	(void)argc;
	(void)argv;
	return (shell_loop(envp));
}
