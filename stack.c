/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgambey <bgambey@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 15:58:23 by bgambey           #+#    #+#             */
/*   Updated: 2026/11/13 10:58:45 by bgambey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// TODO: remove asserts when tested
#include <assert.h>
#include "stack.h"

int	init_stack(t_stack *stack, size_t size)
{
	int	*content;
   
	content = malloc(size * sizeof(int));
	if (!content)
		return (-1);
	stack->values = content;
	stack->size = size;
	stack->count = 0;
	stack->start = 0;
	return (0);
}

void	destroy_stack(t_stack *stack)
{
	free(stack->values);
}

void	print_stack(t_stack *stack)
{
	for (size_t i = 0; i < stack->count; i++)
		ft_printf("%d ", get_stack_value(stack, i));
	ft_printf("(Bot)\n");
}

static unsigned long	get_real_stack_index(t_stack *stack, unsigned long index)
{
	unsigned long	real_index;

	assert(index < stack->count);
	real_index = stack->start + index;
	if (real_index >= stack->size)
		real_index -= stack->size;
	return (real_index);
}

int	get_stack_value(t_stack *s, unsigned long index)
{
	return (s->values[get_real_stack_index(s, index)]);
}

static void	swap_stack_values(t_stack *stack,
		unsigned long index1, unsigned long index2)
{
	int	tmp;

	if (index1 == index2)
		return ;
	index1 = get_real_stack_index(stack, index1);
	index2 = get_real_stack_index(stack, index2);
	tmp = stack->values[index1];
	stack->values[index1] = stack->values[index2];
	stack->values[index2] = tmp;
}

void	push_value(t_stack *stack, int value)
{
	assert(stack->count + 1 <= stack->size);

	stack->count++;
	stack->values[get_real_stack_index(stack, stack->count - 1)] = value;
}

static int	pop_value(t_stack *stack)
{
	unsigned long	value;

	assert(stack->count > 0);
	value = stack->values[get_real_stack_index(stack, stack->count - 1)];
	stack->count--;
	if (stack->count == 0)
		stack->start = 0; // May (maybe) improve performances (eventually) (dont know much...)
	return (value);
}

void	rotate_stack(t_stack *s) // ra, rb, rr
{
	unsigned long	old_start;
	unsigned long	new_end;

	if (s->count <= 1)
		return ;
	old_start = s->start;
	new_end = s->start + s->count;
	if (new_end >= s->size)
		new_end -= s->size;
	if (++s->start == s->size)
		s->start = 0;
	s->values[new_end] = s->values[old_start];
}

void	rev_rotate_stack(t_stack *s) // rra, rrb rrr
{
	unsigned long	old_end;

	if (s->count <= 1)
		return ;
	if (s->start == 0)
	{
		s->start = s->size - 1;
		s->values[s->start] = s->values[s->count - 1];
		return ;
	}
	s->start--;
	old_end = s->start + s->count;
	if (old_end >= s->size)
		old_end -= s->size;
	s->values[s->start] = s->values[old_end];
}

void	swap_stack_top(t_stack *s) // sa, sb, ss
{
	if (s->count < 2)
		return ;
	swap_stack_values(s, s->count - 1, s->count - 2);
}

void	transfer_stacks(t_stack *dst, t_stack *src) // pa, pb
{
	push_value(dst, pop_value(src));
}
