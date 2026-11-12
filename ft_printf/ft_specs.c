/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgambey <bgambey@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 13:14:18 by bgambey           #+#    #+#             */
/*   Updated: 2026/11/11 16:56:27 by bgambey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	get_spec_index(char spec)
{
	char	*specs;
	char	*index;

	specs = "cspdiuxX%";
	index = ft_strchr(specs, spec);
	if (!index || !*index)
		return (-1);
	return (index - specs);
}

t_length_func	**get_length_functions(void)
{
	static t_length_func	*length_functions[] = {
		get_c_length,
		get_s_length,
		get_p_length,
		get_d_length,
		get_d_length,
		get_u_length,
		get_x_length,
		get_x_length,
		get_percent_length
	};

	return (length_functions);
}

t_write_func	**get_write_functions(void)
{
	static t_write_func	*write_functions[] = {
		write_c,
		write_s,
		write_p,
		write_d,
		write_d,
		write_u,
		write_x,
		write_upper_x,
		write_percent
	};

	return (write_functions);
}
