/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strategy.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epigot <epigot@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 16:06:33 by epigot            #+#    #+#             */
/*   Updated: 2026/11/10 16:06:35 by epigot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRATEGY_H
# define STRATEGY_H

typedef struct s_strategy
{
	char	*category;
	char	*complexity;
}	t_strategy;
t_strategy	*new_strategy();

#endif