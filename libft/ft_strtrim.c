/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epigot <epigot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 12:37:28 by epigot            #+#    #+#             */
/*   Updated: 2026/11/02 15:46:58 by epigot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*s;
	size_t	end_index;

	if (!s1 || !set)
		return (NULL);
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	end_index = ft_strlen(s1);
	while (end_index > 0 && ft_strchr(set, s1[end_index - 1]))
		end_index--;
	s = (char *)malloc(end_index + 1);
	if (!s)
		return (NULL);
	ft_strlcpy(s, s1, end_index + 1);
	return (s);
}
