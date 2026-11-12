/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgambey <bgambey@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 12:47:40 by bgambey           #+#    #+#             */
/*   Updated: 2026/11/11 16:55:12 by bgambey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stddef.h>

# define FMT_CHAR '%'

struct	s_printf_ctx
{
	char			*output;
	unsigned int	i;
};

typedef size_t	t_length_func(va_list *);
typedef char	*t_write_func(char *, va_list *);

size_t			get_c_length(va_list *arg);
char			*write_c(char *dst, va_list *arg);
size_t			get_d_length(va_list *arg);
char			*write_d(char *dst, va_list *arg);
size_t			get_percent_length(va_list *arg);
char			*write_percent(char *dst, va_list *arg);
size_t			get_s_length(va_list *arg);
char			*write_s(char *dst, va_list *arg);
size_t			get_u_length(va_list *arg);
char			*write_u(char *dst, va_list *arg);
size_t			get_p_length(va_list *arg);
char			*write_p(char *dst, va_list *arg);
size_t			get_x_length(va_list *arg);
char			*write_x(char *dst, va_list *arg);
char			*write_upper_x(char *dst, va_list *arg);
int				get_spec_index(char spec);
t_length_func	**get_length_functions(void);
t_write_func	**get_write_functions(void);
char			hexdigit(char index, int case_);

int				ft_vdprintf(int fd, const char *format, va_list *args);
int				ft_dprintf(int fd, const char *format, ...);
int				ft_printf(const char *format, ...);

#endif
