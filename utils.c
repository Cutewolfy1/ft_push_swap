/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epigot <epigot@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 12:36:57 by epigot            #+#    #+#             */
/*   Updated: 2026/11/10 12:37:00 by epigot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include "strategy.h"
#include "operation.h"

void	print_float(float f, int precision)
{
	int		integer_part;
	int		decimal_part;

	integer_part = (int)f;
	ft_putnbr_signed(integer_part);
	print_char('.');
	f -= (float)integer_part;
	decimal_part = f;
	while (precision)
	{
		f *= 10;
		precision--;
	}
	decimal_part = f;
	ft_putnbr_signed(decimal_part);
}

void	print_bench(float disorder, t_strategy *strat, int op_total,
		t_operation *op_list)
{
	ft_printf("disorder: ");
	print_float(disorder, 2);
	ft_printf("%%\n");
	ft_printf("strategy: %s / %s\n", strat->category, strat->complexity);
	ft_printf("total_ops: %d\n", op_total);
	ft_printf("sa: %d sb: %d ss: %d pa: %d pb: %d\n", op_list->sa, op_list->sb,
		op_list->ss, op_list->pa, op_list->pb);
	ft_printf("ra: %d rb: %d rr: %d rra: %d rrb: %d rrr: %d\n", op_list->ra,
		op_list->rb, op_list->rr, op_list->rra, op_list->rrb, op_list->rrr);
}
