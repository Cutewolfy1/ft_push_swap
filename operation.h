/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epigot <epigot@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 16:06:33 by epigot            #+#    #+#             */
/*   Updated: 2026/11/13 15:59:30 by bgambey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATION_H
# define OPERATION_H

#include <stddef.h>
#include <stdlib.h>
#include "libft.h"

typedef enum e_opcode
{
	SA,
	SB,
	SS,
	PA,
	PB,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR,
	OP_COUNT
} t_opcode;

typedef struct s_op_list
{
	char	*list;
	size_t	size;
	size_t	index;
	char	counts[OP_COUNT];
} t_op_list;

char	*get_op_name(t_opcode code);
int		new_op_list(t_op_list *op_list, size_t size_estimation);
int		add_operation(t_op_list *op_list, t_opcode op);
void	destroy_op_list(t_op_list *op_list);

#endif
