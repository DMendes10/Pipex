/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diomende <diomende@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 18:46:41 by diomende          #+#    #+#             */
/*   Updated: 2025/05/05 17:22:55 by diomende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putpointer(void *ptr, unsigned long long base, char *set, \
unsigned int starter)
{
	int					i;
	unsigned long long	plong;

	i = 0;
	plong = (unsigned long long) ptr;
	if (!ptr)
		return (write (1, "(nil)", 5));
	if (starter++ == 0)
		i += write (1, "0x", 2);
	if (plong >= base)
		i += ft_putpointer ((void *)(plong / base), base, set, starter);
	i += ft_putchar (set[plong % base]);
	return (i);
}
