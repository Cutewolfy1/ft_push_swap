/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_algo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epigot <epigot@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 10:25:12 by epigot            #+#    #+#             */
/*   Updated: 2026/11/13 16:24:12 by bgambey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "operation.h"

static int get_smallest_index(const t_stack *stack)
{
	unsigned long	i;
	unsigned long	smallest_index;
	int smallest_value;
	int	current_value;

	if (stack->count <= 0)
		return (-1);
	smallest_index = 0;
	smallest_value = get_stack_value(stack, 0);
	i = 1;
	while (i < stack->count)
	{
		current_value = get_stack_value(stack, i);
		if (current_value < smallest_value)
		{
			smallest_value = current_value;
			smallest_index = i;
		}
		i++;
	}
	return (smallest_index);
}

void sort_three(t_stack *stack)
{
	int a;
	int b;
	int c;

	if (stack->count != 3)
		return ;
	a = get_stack_value(stack, 2);
	b = get_stack_value(stack, 1);
	c = get_stack_value(stack, 0);
	if (a < b && b > c && a < c)
	{
		swap_stack_top(stack);
		rotate_stack(stack);
	}
	else if (a > b && b < c && a < c)
		swap_stack_top(stack);
	else if (a < b && b > c && a > c)
		rev_rotate_stack(stack);
	else if (a > b && b < c && a > c)
		rotate_stack(stack);
	else if (a > b && b > c && a > c)
	{
		swap_stack_top(stack);
		rev_rotate_stack(stack);
	}
}

void sort_simple(t_stack *a, t_op_list *)
{
	t_stack			b;
	unsigned long	index;
	int				moves;

	init_stack(&b, a->size);
	while (a->count > 3)
	{
		index = get_smallest_index(a);
		if (index >= a->count / 2)
		{
			moves = a->count - index - 1;
			while (moves-- > 0)
				rotate_stack(a);
		}
		else
		{
			rev_rotate_stack(a);
			while (index-- > 0)
				rev_rotate_stack(a);
		}
		transfer_stacks(&b, a);
	}
	sort_three(a);
	// FIXME if s->count == 2; (not enough lines...)
	while (b.count > 0)
		transfer_stacks(a, &b);
	free(b.values);
}
