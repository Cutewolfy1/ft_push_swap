/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgambey <bgambey@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 13:27:04 by bgambey           #+#    #+#             */
/*   Updated: 2026/11/07 17:15:26 by bgambey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	get_int_length(long n)
{
	size_t	length;

	length = 0;
	if (n <= 0)
	{
		length++;
		n = -n;
	}
	while (n)
	{
		n /= 10;
		length++;
	}
	return (length);
}

size_t	get_d_length(va_list *arg)
{
	long	n;

	n = va_arg(*arg, int);
	return (get_int_length(n));
}

char	*write_d(char *dst, va_list *arg)
{
	size_t	length;
	long	n;
	int		i;

	n = va_arg(*arg, int);
	length = get_int_length(n);
	dst[0] = '-';
	if (n < 0)
		n = -n;
	else if (n == 0)
		dst[0] = '0';
	i = length - 1;
	while (n > 0)
	{
		dst[i] = n % 10 + '0';
		n /= 10;
		i--;
	}
	return (dst + length);
}
