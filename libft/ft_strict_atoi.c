/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_of.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epigot <epigot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/17 19:51:48 by epigot            #+#    #+#             */
/*   Updated: 2026/11/13 10:54:25 by bgambey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "libft.h"

int	ft_strict_atoi(const char *nptr, int *dst)
{
	long	result;
	size_t	i;
	int		sign;

	result = 0;
	i = 0;
	sign = 0;
	while (ft_isspace(nptr[i]))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		sign = nptr[i] == '-';
		i++;
	}
	while (nptr[i])
	{
		if (!ft_isdigit(nptr[i]))
			return (-1);
		result = result * 10 + nptr[i] - '0';
		if (result > (long) INT_MAX + sign)
			return (-1);
		i++;
	}
	if (sign)
		result = -result;
	*dst = result;
	return (0);
}
