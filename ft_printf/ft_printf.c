/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgambey <bgambey@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/05 15:29:46 by bgambey           #+#    #+#             */
/*   Updated: 2026/11/11 16:56:15 by bgambey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

static size_t	get_spec_length(char spec, va_list *args)
{
	int		index;

	index = get_spec_index(spec);
	if (index < 0)
		return (2);
	return (get_length_functions()[index](args));
}

static ssize_t	get_string_length(const char *format, va_list *args)
{
	int		i;
	ssize_t	length;

	length = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == FMT_CHAR)
		{
			i++;
			if (!format[i])
				return (-1);
			length += get_spec_length(format[i], args);
		}
		else
			length++;
		i++;
	}
	return (length);
}

static void	fill_in_string(char *dst, char const *format, va_list *args)
{
	int		index;

	while (*format)
	{
		if (*format == FMT_CHAR)
		{
			format++;
			index = get_spec_index(*format);
			if (index < 0)
			{
				*(dst++) = FMT_CHAR;
				*(dst++) = *format;
			}
			else
				dst = get_write_functions()[index](dst, args);
		}
		else
			*(dst++) = *format;
		format++;
	}
}

int	ft_vdprintf(int fd, const char *format, va_list *args)
{
	ssize_t	length;
	char	*string;
	va_list	copy;

	if (!format)
		return (-1);
	va_copy(copy, *args);
	length = get_string_length(format, args);
	if (length < 0)
		return (length);
	string = malloc(length);
	if (!string)
		return (-1);
	fill_in_string(string, format, &copy);
	va_end(copy);
	write(fd, string, length);
	free(string);
	return (length);
}

int	ft_dprintf(int fd, const char *format, ...)
{
	va_list	args;
	int		ret;

	va_start(args, format);
	ret = ft_vdprintf(fd, format, &args);
	va_end(args);
	return (ret);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		ret;

	va_start(args, format);
	ret = ft_vdprintf(1, format, &args);
	va_end(args);
	return (ret);
}
