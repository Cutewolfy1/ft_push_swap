/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epigot <epigot@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 12:40:22 by epigot            #+#    #+#             */
/*   Updated: 2026/11/10 12:40:24 by epigot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "strategy.h"
# include "operation.h"

void	ft_putstring(char *str);
void	print_bench(float disorder, t_strategy *strat, int op_total,
		t_operation *op_list);

#endif
