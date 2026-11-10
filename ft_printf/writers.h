/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writers.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epigot <epigot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 10:40:04 by epigot            #+#    #+#             */
/*   Updated: 2026/11/04 10:45:10 by epigot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRITERS_H
# define WRITERS_H

# include <stdlib.h> 
# include <unistd.h>

void	ft_putchar(char c);
size_t	ft_putnbr_unsigned(unsigned int n);
size_t	ft_putnbr_signed(int nbr);

#endif