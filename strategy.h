/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strategy.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epigot <epigot@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 16:06:33 by epigot            #+#    #+#             */
/*   Updated: 2026/11/12 15:11:57 by bgambey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRATEGY_H
# define STRATEGY_H

typedef enum e_strat_id
{ 
    SIMPLE = 0, 
    MEDIUM, 
    COMPLEX, 
    ADAPTATIVE, 
    STRAT_COUNT 
} t_strat_id; 

typedef struct s_strategy
{
	t_strat_id	id;
	char		*category;
	char		*complexity;
}	t_strategy;

t_strategy	*new_strategy(void);

#endif
