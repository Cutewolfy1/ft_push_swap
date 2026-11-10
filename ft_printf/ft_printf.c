/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epigot <epigot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 10:13:00 by epigot            #+#    #+#             */
/*   Updated: 2026/11/06 15:19:07 by epigot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_special(const char *string, va_list args)
{
	if (*(string + 1) == '%')
		return (print_char('%'));
	if (*(string + 1) == 'c')
		return (print_char((char) va_arg(args, int)));
	if (*(string + 1) == 's')
		return (print_string((char *) va_arg(args, char *)));
	if (*(string + 1) == 'p')
		return (print_void((void *) va_arg(args, void *)));
	if (*(string + 1) == 'd' || *(string + 1) == 'i')
		return (ft_putnbr_signed((int) va_arg(args, int)));
	if (*(string + 1) == 'u')
		return (ft_putnbr_unsigned((unsigned int) va_arg(args, unsigned int)));
	if (*(string + 1) == 'x' || *(string + 1) == 'X')
		return (print_hex((unsigned int) va_arg(args, unsigned int),
				*(string + 1)));
	ft_putchar('%');
	ft_putchar(*(string + 1));
	return (2);
}

int	ft_printf(const char *string, ...)
{
	int		char_count;
	va_list	args;

	char_count = 0;
	va_start(args, string);
	while (*string)
	{
		if (*string != '%')
		{
			ft_putchar(*string);
			char_count++;
			string++;
			continue ;
		}
		if (*(string + 1) == '\0')
		{
			ft_putchar('%');
			char_count++;
			break ;
		}
		char_count += print_special(string, args);
		string += 2;
	}
	va_end(args);
	return (char_count);
}
