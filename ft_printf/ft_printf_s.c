/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgambey <bgambey@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 13:27:04 by bgambey           #+#    #+#             */
/*   Updated: 2026/11/11 16:56:19 by bgambey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

size_t	get_s_length(va_list *arg)
{
	char	*s;

	s = va_arg(*arg, char *);
	if (!s)
		return (6);
	return (ft_strlen(s));
}

char	*write_s(char *dst, va_list *arg)
{
	char	*s;
	size_t	length;

	s = va_arg(*arg, char *);
	if (!s)
	{
		s = "(null)";
		length = 6;
	}
	else
		length = ft_strlen(s);
	ft_memcpy(dst, s, length);
	return (dst + length);
}
