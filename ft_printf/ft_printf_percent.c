/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_percent.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgambey <bgambey@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 13:27:04 by bgambey           #+#    #+#             */
/*   Updated: 2026/11/09 13:13:52 by bgambey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	get_percent_length(va_list *arg)
{
	(void) arg;
	return (1);
}

char	*write_percent(char *dst, va_list *arg)
{
	(void) arg;
	*dst = FMT_CHAR;
	return (dst + 1);
}
