/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epigot <epigot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 23:12:44 by epigot            #+#    #+#             */
/*   Updated: 2026/11/05 15:05:51 by epigot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*bytes;
	unsigned char		uc;

	bytes = (const unsigned char *)s;
	uc = (unsigned char)c;
	while (n)
	{
		if (*bytes == uc)
			return ((void *)bytes);
		bytes++;
		n--;
	}
	return (NULL);
}
