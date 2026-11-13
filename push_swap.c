/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epigot <epigot@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 12:24:22 by epigot            #+#    #+#             */
/*   Updated: 2026/11/13 16:44:10 by bgambey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_solve_method(int *array, int length)
{
	int	index;

	index = 0;
	while (length--)
	{
		if (array[length] == 0)
			continue ;
		if (index)
			return (-1);
		index = length;
	}
	return (index);
}

static int	stack_from_strings(char **numbers, int count, t_stack *stack)
{
	int	i;
	int	number;

	if (init_stack(stack, count) < 0)
		return (-1);
	i = 0;
	while (i < count)
	{
		if (ft_strict_atoi(numbers[i], &number) < 0)
			return (destroy_stack(stack), -1);
		if (index_of(stack, number) >= 0)
			return (destroy_stack(stack), -1);
		push_value(stack, number);
		rotate_stack(stack); // TODO: fill stack->values directly
		i++;
	}
	return (0);
}

static int	parse_args(int argc, char **argv, t_push_swap_ctx *ctx)
{
	t_parser	parser;
	int			solve_methods[STRAT_COUNT];
	int			is_bench;
	int			ret;
	int			solve_method;

	ft_memset(solve_methods, 0, sizeof(solve_methods));
	is_bench = 0;
	if (new_parser(&parser, 5, FLAG_SILENT) < 0)
		return (-1);
	parser.params[0] = (const t_param) {"bench", -1, 1, &is_bench, T_BOOL};
	parser.params[1] = (const t_param) {"simple", -1, 1, solve_methods + SIMPLE, T_BOOL};
	parser.params[2] = (const t_param) {"medium", -1, 1, solve_methods + MEDIUM, T_BOOL};
	parser.params[3] = (const t_param) {"complex", -1, 1, solve_methods + COMPLEX, T_BOOL};
	parser.params[4] = (const t_param) {"adaptative", -1, 1, solve_methods + ADAPTATIVE, T_BOOL};
	ret = parse(&parser, argc, argv);
	destroy_parser(&parser);
	if (ret < 0)
		return (-1);
	solve_method = get_solve_method(solve_methods, STRAT_COUNT);
	if (solve_method < 0)
		return (-1);
	ctx->strategy = solve_method;
	ctx->is_bench = is_bench;
	if (stack_from_strings(argv + ret, argc - ret, &ctx->stk) < 0)
		return (-1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_push_swap_ctx	ctx;

	ctx = (t_push_swap_ctx) {0};
	if (argc <= 1)
		return (0);
	if (parse_args(argc, argv, &ctx) < 0)
		return (ft_dprintf(2, "Error\n"), 1);
	if (ctx.stk.count == 0)
		return (destroy_stack(&ctx.stk), ft_dprintf(2, "Error1\n"), 1);
	ctx.algo = find_algorithm(ctx.strategy);
	if (!ctx.algo)
		return (destroy_stack(&ctx.stk), ft_dprintf(2, "Error2\n"), 1);
	if (new_op_list(&ctx.op_list, ctx.stk.size * ctx.stk.size) < 0)
		return (destroy_stack(&ctx.stk), ft_dprintf(2, "Error3\n"), 1); // FIXME, remove figits after errors
	print_stack(&ctx.stk, 2);
	ctx.algo->solve(&ctx.stk, &ctx.op_list);
	print_stack(&ctx.stk, 1);
	destroy_op_list(&ctx.op_list);
	destroy_stack(&ctx.stk);
	return (0);
}
