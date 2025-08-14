/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diomende <diomende@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 14:36:20 by diomende          #+#    #+#             */
/*   Updated: 2025/05/05 17:22:58 by diomende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(long n)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		i += ft_putchar('-');
		n = n * -1;
		i += ft_putnbr (n);
	}
	else if (n > 9)
	{
		i += ft_putnbr (n / 10);
		i += ft_putnbr (n % 10);
	}
	else
		i += ft_putchar (n + 48);
	return (i);
}
