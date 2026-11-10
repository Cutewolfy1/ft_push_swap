/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgambey <bgambey@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 17:26:18 by bgambey           #+#    #+#             */
/*   Updated: 2026/11/10 17:51:20 by bgambey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include <stdlib.h>

typedef struct s_stack
{
	int				*values;
	size_t			size;
	size_t			count;
	unsigned long	start;
}	t_stack;

int		init_stack(t_stack *stack, size_t size);
void	destroy_stack(t_stack *stack);
int		get_stack_value(t_stack *s, unsigned long index);
void	push_value(t_stack *stack, int value);
void	rotate_stack(t_stack *s);
void	rev_rotate_stack(t_stack *s);
void	swap_stack_top(t_stack *s);
void	transfer_stacks(t_stack *dst, t_stack *src);

#endif
