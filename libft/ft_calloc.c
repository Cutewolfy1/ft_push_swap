/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epigot <epigot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/17 21:10:25 by epigot            #+#    #+#             */
/*   Updated: 2026/11/05 17:06:43 by epigot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t n, size_t size)
{
	void	*ptr;

	if (size && n > (size_t)-1 / size)
		return (NULL);
	ptr = (void *)malloc(n * size);
	if (ptr)
	{
		ft_memset(ptr, 0, n * size);
	}
	return (ptr);
}
