/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epigot <epigot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 10:37:10 by epigot            #+#    #+#             */
/*   Updated: 2026/11/04 10:41:16 by epigot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "writers.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

size_t	ft_putnbr_unsigned(unsigned int n)
{
	size_t	count;

	count = 0;
	if (n >= 10)
		count += ft_putnbr_unsigned(n / 10);
	ft_putchar('0' + (n % 10));
	return (count + 1);
}

size_t	ft_putnbr_signed(int nbr)
{
	size_t			size;
	unsigned int	n;

	size = 0;
	if (nbr < 0)
	{
		ft_putchar('-');
		size++;
		n = (unsigned int)(-(nbr + 1)) + 1;
	}
	else
		n = (unsigned int)nbr;
	if (n >= 10)
		size += ft_putnbr_unsigned(n / 10);
	ft_putchar('0' + (n % 10));
	return (size + 1);
}
