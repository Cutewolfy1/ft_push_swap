/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgambey <bgambey@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 13:27:04 by bgambey           #+#    #+#             */
/*   Updated: 2026/11/07 17:15:58 by bgambey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	get_uint_length(unsigned int n)
{
	size_t	length;

	length = 1;
	n /= 10;
	while (n)
	{
		n /= 10;
		length++;
	}
	return (length);
}

size_t	get_u_length(va_list *arg)
{
	unsigned int	n;

	n = va_arg(*arg, unsigned int);
	return (get_uint_length(n));
}

char	*write_u(char *dst, va_list *arg)
{
	size_t			length;
	unsigned int	n;
	int				i;

	n = va_arg(*arg, unsigned int);
	length = get_uint_length(n);
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
