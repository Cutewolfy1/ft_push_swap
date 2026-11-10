/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epigot <epigot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 12:53:40 by epigot            #+#    #+#             */
/*   Updated: 2026/11/04 10:42:05 by epigot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_utils.h"

static int	count_hex_elem(size_t n)
{
	int	count;

	count = 1;
	while (n >= 16)
	{
		n /= 16;
		count++;
	}
	return (count);
}

char	ft_toupper(char c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}

char	*dec_to_hex(size_t n)
{
	char	*result_string;
	int		size;
	int		i;

	size = count_hex_elem(n);
	result_string = (char *)malloc(sizeof(char) * (size + 1));
	if (!result_string)
		return (NULL);
	result_string[size] = '\0';
	i = size;
	while (i > 0)
	{
		i--;
		if ((n % 16) < 10)
			result_string[i] = (n % 16) + '0';
		else
			result_string[i] = (n % 16) - 10 + 'a';
		n /= 16;
	}
	return (result_string);
}
