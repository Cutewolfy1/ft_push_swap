/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgambey <bgambey@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 13:27:04 by bgambey           #+#    #+#             */
/*   Updated: 2026/11/07 17:16:08 by bgambey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	get_uint_x_length(unsigned int n)
{
	size_t	length;

	length = 1;
	n /= 16;
	while (n)
	{
		n /= 16;
		length++;
	}
	return (length);
}

size_t	get_x_length(va_list *arg)
{
	unsigned int	n;

	n = va_arg(*arg, unsigned int);
	return (get_uint_x_length(n));
}

static char	*write_x_case(char *dst, va_list *arg, int case_)
{
	size_t			length;
	unsigned int	n;
	int				i;

	n = va_arg(*arg, unsigned int);
	length = get_uint_x_length(n);
	dst[0] = '0';
	i = length - 1;
	while (n > 0)
	{
		dst[i] = hexdigit(n % 16, case_);
		n /= 16;
		i--;
	}
	return (dst + length);
}

char	*write_x(char *dst, va_list *arg)
{
	return (write_x_case(dst, arg, 0));
}

char	*write_upper_x(char *dst, va_list *arg)
{
	return (write_x_case(dst, arg, 1));
}
