/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epigot <epigot@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 12:24:22 by epigot            #+#    #+#             */
/*   Updated: 2026/11/10 12:24:28 by epigot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	handle_invalid_args(int argc, char **args)
{
	int	i;

	i = 0;
	while (i < argc)
	{
		ft_putstring(args[i]);
		if (i <= argc - 1)
			ft_putstring(" ");
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	if (argc == 1)
		return (handle_invalid_args(argc, argv));
	return (0);
}
