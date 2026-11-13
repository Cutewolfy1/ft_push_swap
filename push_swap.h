/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgambey <bgambey@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 12:26:39 by bgambey           #+#    #+#             */
/*   Updated: 2026/11/13 15:57:58 by bgambey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>
# include "libft.h"

# include "operation.h"
# include "algorithm.h"
# include "argparser.h"
# include "stack.h"

typedef struct s_push_swap_ctx
{
	t_strat_id	strategy;
	t_algorithm	*algo;
	int			is_bench;
	t_stack		stk;
	t_op_list	op_list;
}	t_push_swap_ctx;

#endif
