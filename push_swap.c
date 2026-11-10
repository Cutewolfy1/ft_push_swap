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
#include "operation.h"
#include "strategy.h"
#include "libft/libft.h"

int	handle_invalid_args(int argc, char **args)
{
	int	i;

	i = 0;
	while (i < argc)
	{
		ft_putstr_fd(args[i], 1);
		if (i <= argc - 1)
			ft_putstr_fd(" ", 1);
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	//float		start_disorder;
	int			i;
	t_strategy	*strategy;
	t_operation	*operation;

	i = 0;
	if (argc == 1)
		return (handle_invalid_args(argc, argv));
	while (i < argc - 1)
	{
		if (ft_strncmp(argv[i], "--bench", 7))
		{
			strategy = new_strategy();
			strategy->category = "Simple";
			strategy->complexity = "O(n2)";
			operation = new_operation();
			operation->sa = 1;
			operation->sb = 2;
			operation->ss = 3;
			operation->pa = 4;
			operation->pb = 5;
			operation->ra = 6;
			operation->rb = 7;
			operation->rr = 8;
			operation->rra = 9;
			operation->rrb = 10;
			operation->rrr = 11;
			print_bench(40.58f, strategy, 20, operation);
		}
		i++;
	}
	return (0);
}
