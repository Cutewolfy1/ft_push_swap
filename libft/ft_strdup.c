/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epigot <epigot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/17 21:35:29 by epigot            #+#    #+#             */
/*   Updated: 2026/11/02 15:46:46 by epigot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	s_len;
	char	*dup_str;
	size_t	i;

	s_len = ft_strlen(s);
	dup_str = malloc(s_len + 1);
	if (dup_str == NULL)
		return (NULL);
	i = 0;
	while (i < s_len)
	{
		dup_str[i] = s[i];
		i++;
	}
	dup_str[i] = '\0';
	return (dup_str);
}
