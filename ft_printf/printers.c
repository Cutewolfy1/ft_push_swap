/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epigot <epigot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 10:33:12 by epigot            #+#    #+#             */
/*   Updated: 2026/11/04 10:41:38 by epigot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printers.h"
#include "ft_printf_utils.h"

size_t	print_char(char c)
{
	ft_putchar(c);
	return (1);
}

size_t	print_string(char *s)
{
	size_t	size;

	size = 0;
	if (!s)
		s = "(null)";
	while (s[size])
	{
		ft_putchar(s[size]);
		size++;
	}
	return (size);
}

size_t	print_hex(unsigned int n, char format)
{
	size_t	count;
	char	*hex;

	count = 0;
	if (n == 0)
	{
		ft_putchar('0');
		return (1);
	}
	hex = dec_to_hex((size_t)n);
	if (format == 'X')
	{
		while (hex[count])
		{
			ft_putchar(ft_toupper(hex[count]));
			count++;
		}
	}
	else
		count += print_string(hex);
	free(hex);
	return (count);
}

size_t	print_void(void *p)
{
	size_t	size;
	char	*hex_addr;

	size = 0;
	if (!p)
		return (print_string("(nil)"));
	hex_addr = dec_to_hex((size_t)p);
	size += print_string("0x");
	size += print_string(hex_addr);
	free(hex_addr);
	return (size);
}
