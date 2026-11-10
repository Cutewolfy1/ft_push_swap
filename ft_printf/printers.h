/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printers.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epigot <epigot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 10:34:12 by epigot            #+#    #+#             */
/*   Updated: 2026/11/04 10:46:17 by epigot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTERS_H
# define PRINTERS_H

# include <stdlib.h>
# include "writers.h"

size_t	print_char(char c);
size_t	print_string(char *s);
size_t	print_hex(unsigned int n, char format);
size_t	print_void(void *p);

#endif