/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgambey <bgambey@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 13:27:04 by bgambey           #+#    #+#             */
/*   Updated: 2026/11/11 16:56:23 by bgambey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static size_t	get_ulong_length(unsigned long n)
{
	size_t			length;

	length = 1;
	n /= 16;
	while (n)
	{
		n /= 16;
		length++;
	}
	return (length);
}

size_t	get_p_length(va_list *arg)
{
	unsigned long	n;

	n = (unsigned long) va_arg(*arg, void *);
	if (!n)
		return (5);
	return (get_ulong_length(n) + 2);
}

char	*write_p(char *dst, va_list *arg)
{
	size_t			length;
	unsigned long	n;
	int				i;

	n = (unsigned long) va_arg(*arg, void *);
	if (!n)
	{
		ft_memcpy(dst, "(nil)", 5);
		return (dst + 5);
	}
	*(dst++) = '0';
	*(dst++) = 'x';
	length = get_ulong_length(n);
	dst[0] = '0';
	i = length - 1;
	while (n > 0)
	{
		dst[i] = hexdigit(n % 16, 0);
		n /= 16;
		i--;
	}
	return (dst + length);
}
