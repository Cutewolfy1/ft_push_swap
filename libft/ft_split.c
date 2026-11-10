/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epigot <epigot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 15:09:48 by epigot            #+#    #+#             */
/*   Updated: 2026/11/04 16:37:28 by epigot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(const char *s, char c)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
			count++;
		while (*s && *s != c)
			s++;
	}
	return (count);
}

static char	*allocate_word(const char *s, char c)
{
	char	*word;
	size_t	word_len;

	word_len = 0;
	while (*s && *s == c)
		s++;
	while (s[word_len] && s[word_len] != c)
		word_len++;
	word = (char *)malloc(word_len + 1);
	if (!word)
		return (NULL);
	ft_strlcpy(word, s, word_len + 1);
	return (word);
}

static void	clear(char **result, int clear_up_to)
{
	int	i;

	i = 0;
	while (i < clear_up_to)
	{
		free(result[i]);
		i++;
	}
	free(result);
}

static int	get_words(char const *s, char c, char **result, size_t word_count)
{
	size_t	i;

	i = 0;
	while (i < word_count)
	{
		while (*s && *s == c)
			s++;
		result[i] = allocate_word(s, c);
		if (!result[i])
		{
			clear(result, i);
			return (1);
		}
		while (*s && *s != c)
			s++;
		i++;
	}
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	size_t	word_count;

	if (!s)
		return (NULL);
	word_count = count_words(s, c);
	result = (char **)malloc((word_count + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	result[word_count] = NULL;
	if (get_words(s, c, result, word_count))
		return (NULL);
	return (result);
}
