/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diomende <diomende@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 17:44:10 by diomende          #+#    #+#             */
/*   Updated: 2025/05/05 17:20:56 by diomende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthexa(unsigned int n, char c)
{
	unsigned int	base;
	int				i;
	char			*set;

	i = 0;
	base = 16;
	if (c == 'x')
		set = "0123456789abcdef";
	else
		set = "0123456789ABCDEF";
	if (n >= base)
		i += ft_puthexa (n / base, c);
	i += ft_putchar (set [n % base]);
	return (i);
}
