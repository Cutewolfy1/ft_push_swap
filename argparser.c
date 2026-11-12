/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argparser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgambey <bgambey@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 10:47:54 by bgambey           #+#    #+#             */
/*   Updated: 2026/11/12 12:09:22 by bgambey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "argparser.h"

int	new_parser(t_parser *parser, int param_count, int flags)
{
	t_param	*params;

	params = malloc(param_count * sizeof(t_param));
	if (!params)
		return (-1);
	parser->params = params;
	parser->param_count = param_count;
	parser->flags = flags;
	parser->argv = nullptr;
	parser->argc = 0;
	parser->argc = 0;
	return (0);
}

void	destroy_parser(t_parser *parser)
{
	free(parser->params);
}

static int	take_action(t_parser *ctx, t_param *param, int arg_type)
{
	if (param->type == T_BOOL)
	{
		if (param->dest)
			*(int *) param->dest = 1;
		return (0);
	}
	if (ctx->i + 1 >= ctx->argc)
	{
		if (arg_type && !(ctx->flags & FLAG_SILENT))
			ft_dprintf(2, "%s: Expected argument after '--%s'\n", ctx->argv[0],
					param->longname);
		else if (!(ctx->flags & FLAG_SILENT))
			ft_dprintf(2, "%s: Expected argument after '-%c'\n", ctx->argv[0],
					param->shortname);
		return (-1);
	}
	ctx->i++;
	if (param->type == T_STR)
	{
		if (param->dest)
			*(char **) param->dest = ctx->argv[ctx->i];
		return (0);
	}
	ft_dprintf(2, "FATAL: Internal error: unknown type: %d\n", param->type);
	return (-1);
}


static int	parse_long_arg(t_parser *ctx, char *arg)
{
	int		i;
	t_param	*param;

	i = 0;
	while (i < ctx->param_count)
	{
		param = ctx->params + i;
		if (!param->longname)
			continue ;
		if (!ft_strcmp(arg, param->longname))
			return (take_action(ctx, param, 1));
		i++;
	}
	if (!(ctx->flags & FLAG_SILENT))
		ft_dprintf(2, "%s: unrecognized option: '--%s'\n", ctx->argv[0], arg);
	return (-1);
}

static int	parse_short_arg(t_parser *ctx, char arg)
{
	int		i;
	t_param	*param;

	i = -1;
	while (++i < ctx->param_count)
	{
		param = ctx->params + i;
		if (param->shortname == -1)
			continue ;
		if (arg == param->shortname)
			return (take_action(ctx, param, 0));
	}
	if (!(ctx->flags & FLAG_SILENT))
		ft_dprintf(2, "%s: unrecognized option: '-%c'\n", ctx->argv[0], arg);
	return (-1);
}

/*
 * Returns 0 when ok,
 * Returns > 0 if parsing should stop
 * Returns < 0 if parsing failed (Unknown option or missing option)
 */
static int	parse_arg(t_parser *ctx, char *arg)
{
	int	ret;

	if (arg[1] == '-')
	{
		if (!arg[2])
			return (1);
		return (parse_long_arg(ctx, arg + 2));
	}
	if (!arg[1] || arg[2])
		return (-1);
	arg++;
	while (*arg)
	{
		ret = parse_short_arg(ctx, *arg);
		if (ret < 0)
			return (ret);
		arg++;
	}
	return (0);
}

unsigned long	parse(t_parser *ctx, int argc, char **argv)
{
	int		ret;
	char	*arg;

	ctx->argv = argv;
	ctx->argc = argc;
	ctx->i = 1;
	while (ctx->i < ctx->argc)
	{
		arg = ctx->argv[ctx->i];
		if (arg[0] != '-')
			break ;
		ret = parse_arg(ctx, arg);
		if (ret < 0)
			return (ret);
		if (ret > 0)
			break ;
		ctx->i++;
	}
	return (ctx->i);
}
