/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgambey <bgambey@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 15:58:54 by bgambey           #+#    #+#             */
/*   Updated: 2026/11/13 16:01:04 by bgambey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operation.h"

char	*get_op_name(t_opcode code)
{
	static char *op_names[OP_COUNT] = {
		[SA] = "sa",
		[SB] = "sb",
		[SS] = "ss",
		[PA] = "pa",
		[PB] = "pb",
		[RA] = "ra",
		[RB] = "rb",
		[RR] = "rr",
		[RRA] = "rra",
		[RRB] = "rrb",
		[RRR] = "rrr",
	};

	return (op_names[code]);
}

int	new_op_list(t_op_list *op_list, size_t size_estimation)
{
	char	*list;

	list = malloc(size_estimation);
	if (!list)
		return (-1);
	op_list->list = list;
	op_list->size = size_estimation;
	op_list->index = 0;
	ft_bzero(op_list->counts, sizeof(op_list->counts));
	return (0);
}

void	destroy_op_list(t_op_list *op_list)
{
	free(op_list->list);
}

// Not reliable, not optimized, ...
static int	ft_realloc(void **s, size_t old_size, size_t new_size)
{
	char	*new_ptr;
	char	*old_ptr;

	new_ptr = malloc(new_size);
	if (!new_ptr)
		return (-1);
	old_ptr = *s;
	ft_memcpy(new_ptr, old_ptr, old_size);
	free(old_ptr);
	*s = (void *) new_ptr;
	return (0);
}

static int	cancels_out(t_opcode a, t_opcode b)
{
	t_opcode	tmp;

	if (a > b)
	{
		tmp = a;
		a = b;
		b = tmp;
	}
	if (a == PA && b == PB)
		return (1);
	if (a == RA && b == RRA)
		return (1);
	if (a == RB && b == RRB)
		return (1);
	if (a == RR && b == RRR)
		return (1);
	if (a == SA && b == SA)
		return (1);
	if (a == SB && b == SB)
		return (1);
	if (a == SS && b == SS)
		return (1);
	return (0);
}

/* Returns -1 if a and b cannot be simplified */
static t_opcode	simplifies(t_opcode a, t_opcode b)
{
	t_opcode	tmp;
	
	if (a > b)
	{
		tmp = a;
		a = b;
		b = tmp;
	}
	if (a == SA && b == SS)
		return (SB);
	if (a == SB && b == SS)
		return (SA);
	if (a == RA && b == RRR)
		return (RB);
	if (a == RB && b == RRR)
		return (RA);
	if (a == RR && b == RRA)
		return (RRB);
	if (a == RR && b == RRB)
		return (RRA);
	return (-1);
}

#include <assert.h> // FIXME
static void	remove_last_op(t_op_list *op_list)
{
	t_opcode	last;

	assert(op_list->index != 0);
	op_list->index--;
	last = op_list->list[op_list->index];
	op_list->counts[last]--;
}

int	add_operation(t_op_list *op_list, t_opcode op)
{
	int	ret;

	if (op_list->index != 0
			&& cancels_out(op_list->list[op_list->index - 1], op))
	{
		op_list->index--;
		return (0);
	}
	ret = simplifies(op_list->list[op_list->index - 1], op);
	if (ret != -1)
		return (remove_last_op(op_list), add_operation(op_list, ret));
	if (op_list->index >= op_list->size)
	{
		ret = ft_realloc((void **) &op_list->list, op_list->size, op_list->size * 2);
		if (ret < 0)
			return (ret);
	}
	op_list->list[op_list->index++] = op;
	op_list->counts[op]++;
	return (0);
}
