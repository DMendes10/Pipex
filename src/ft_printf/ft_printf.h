/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diomende <diomende@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 20:36:26 by diomende          #+#    #+#             */
/*   Updated: 2025/05/05 17:30:23 by diomende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stddef.h>
# include <limits.h>
# include <stdarg.h>
# include <stdlib.h>

int		ft_putstr(char *s);
int		ft_putchar(char c);
int		ft_printf(const char *s, ...);
int		ft_putnbr(long n);
int		ft_putunint(unsigned int n);
int		ft_puthexa(unsigned int n, char c);
int		ft_putpointer(void *ptr, unsigned long long base, char *set, \
unsigned int starter);

#endif