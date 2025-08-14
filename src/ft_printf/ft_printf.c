/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diomende <diomende@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 16:19:15 by diomende          #+#    #+#             */
/*   Updated: 2025/05/05 17:30:45 by diomende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_format_validator(char c)
{
	if (c == '%')
		return (1);
	else if (c == 's')
		return (1);
	else if (c == 'c')
		return (1);
	else if (c == 'd')
		return (1);
	else if (c == 'u')
		return (1);
	else if (c == 'p')
		return (1);
	else if (c == 'x')
		return (1);
	else if (c == 'X')
		return (1);
	else if (c == 'i')
		return (1);
	else
		return (0);
}

static int	ft_choose_format(char c, va_list args)
{
	if (c == '%')
		return (ft_putchar ('%'));
	else if (c == 's')
		return (ft_putstr (va_arg(args, char *)));
	else if (c == 'c')
		return (ft_putchar (va_arg(args, int)));
	else if (c == 'd')
		return (ft_putnbr(va_arg(args, int)));
	else if (c == 'u')
		return (ft_putunint(va_arg (args, unsigned int)));
	else if (c == 'p')
		return (ft_putpointer(va_arg (args, void *), 16, \
"0123456789abcdef", 0));
	else if (c == 'x')
		return (ft_puthexa(va_arg (args, unsigned int), c));
	else if (c == 'X')
		return (ft_puthexa(va_arg (args, unsigned int), c));
	else if (c == 'i')
		return (ft_putnbr(va_arg(args, int)));
	return (0);
}

int	ft_printf(const char *s, ...)
{
	va_list			args;
	unsigned int	i;
	unsigned int	counter;

	if (!s)
		return (-1);
	va_start (args, s);
	counter = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == '%')
		{
			if (!(ft_format_validator(s[i + 1])))
				return (va_end(args), -1);
			counter += ft_choose_format(s[i + 1], args);
			i++;
		}
		else
			counter += ft_putchar (s[i]);
		i++;
	}
	va_end (args);
	return (counter);
}

// #include "ft_printf.h"
// #include <stdio.h>

// int	main(void)
// {
// 	char	letter = 'a';
// 	char	*string = "hello\0";
// 	char	*str = NULL;
// 	int		*ptr = NULL;
// 	int		number = -255;
// 	int		count[13];

// 	ft_printf("\n_____________FT_PRINTF_____________\n");
// 	count[0] = ft_printf("1 | Letter: %c", letter);	  // 12 + 1 (a)
// 	count[1] = ft_printf("\n2 | String: %s", string); //  13 + 5 (hello)
// 	count[2] = ft_printf("\n3 | Number (i): %i", number); // 17 + 4 (-255)
// 	count[2] = ft_printf("\n3 | Number (d): %d", number);
// 	count[3] = ft_printf("\n4 | Unsigned: %u", number);
// 	count[4] = ft_printf("\n5 | Hex lower (x): %x", number);
// 	count[5] = ft_printf("\n6 | Hex UPPER (X): %X", number);
// 	count[6] = ft_printf("\n7 | Pointer: %p", &string);
// 	count[7] = ft_printf("\n8 | NULL string: %s", str);
// 	count[8] = ft_printf("\n9 | Percent sign: %%");
// 	count[9] = ft_printf("\n10 | NULL string direct: %s", str);
// 	count[10] = ft_printf("\n11 | NULL pointer: %p", ptr);
// 	count[11] = ft_printf("\nhello%", string);
// 	count[12] = ft_printf(NULL);

// 	for (int i = 0; i < 13; i++)
// 		printf("\nft_printf count%d: %d", i + 1, count[i]);

// 	printf("\n_______________PRINTF______________\n");
// 	count[0] = printf("1 | Letter: %c", letter);
// 	count[1] = printf("\n2 | String: %s", string);
// 	count[2] = printf("\n3 | Number (i): %i", number);
// 	count[2] = printf("\n3 | Number (d): %d", number);
// 	count[3] = printf("\n4 | Unsigned: %u", number);
// 	count[4] = printf("\n5 | Hex lower (x): %x", number);
// 	count[5] = printf("\n6 | Hex UPPER (X): %X", number);
// 	count[6] = printf("\n7 | Pointer: %p", &string);
// 	count[7] = printf("\n8 | NULL string: %s", str);
// 	count[8] = printf("\n9 | Percent sign: %%");
// 	count[9] = printf("\n10 | NULL string direct: %s", str);
// 	count[10] = printf("\n11 | NULL pointer: %p", ptr);
// 	count[11] = ft_printf("\nhello%", string);
// 	count[12] = ft_printf(NULL);

// 	// printf("%s\n", (char *)NULL);

// 	for (int i = 0; i < 13; i++)
// 		printf("\nprintf count%d: %d", i + 1, count[i]);

// 	printf("\n\nEnd\n");
// 	return (0);
// }