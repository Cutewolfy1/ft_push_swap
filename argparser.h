/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argparser.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgambey <bgambey@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 11:26:25 by bgambey           #+#    #+#             */
/*   Updated: 2026/11/12 12:01:52 by bgambey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARGPARSER_H
# define ARGPARSER_H

# include "ft_printf.h"
# include "libft.h"

enum e_parser_flags
{
	FLAG_SILENT = 1,
};

typedef enum e_paramtpye
{
	T_STR,
	T_BOOL,
}	t_paramtype;

/* Note: this object oriented structure would perform better if data oriented */
typedef struct s_param
{
	char		*longname;
	char		shortname;
	int			optional;
	void		*dest;
	t_paramtype	type;
}	t_param;

typedef struct	s_parser
{
	char			**argv;
	unsigned long	argc;
	unsigned long	i;
	int				flags;
	t_param			*params;
	int				param_count;
}	t_parser;

int				new_parser(t_parser *parser, int param_count, int flags);
unsigned long	parse(t_parser *ctx, int argc, char **argv);
void			destroy_parser(t_parser *parser);

#endif
