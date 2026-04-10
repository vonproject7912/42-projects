/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vonpr <vonpr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 01:55:51 by vonpr             #+#    #+#             */
/*   Updated: 2026/04/10 15:29:20 by vonpr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);
int	ft_print_char(int c);
int	ft_print_str(char *str);
int	ft_print_putnbr(long nbr);
int	ft_print_adress(void *ptrr);
int	ft_print_positf_putnbr(unsigned int nbr);
int	ft_print_hexa(long nbr);
int	ft_print_up_hexa(long nbr);
int	ft_hexa_ptr(uintptr_t nbr);

#endif