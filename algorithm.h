/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epigot <epigot@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 16:06:33 by epigot            #+#    #+#             */
/*   Updated: 2026/11/13 15:58:06 by bgambey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALGORITHM_H
# define ALGORITHM_H

# include "stack.h"
# include "algos.h"

typedef void (*t_solve_func)(t_stack *, t_op_list *);

typedef enum e_strat_id
{ 
    SIMPLE = 0, 
    MEDIUM, 
    COMPLEX, 
    ADAPTATIVE, 
    STRAT_COUNT 
} t_strat_id; 

typedef struct s_algorithm
{
	t_strat_id	strat;
	char		*category;
	char		*complexity;
	t_solve_func	solve;
}	t_algorithm;

t_algorithm	*new_algorithm(void);
t_algorithm	*find_algorithm(t_strat_id strat);

#endif
