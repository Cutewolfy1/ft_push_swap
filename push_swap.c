/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epigot <epigot@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 12:24:22 by epigot            #+#    #+#             */
/*   Updated: 2026/11/12 15:44:34 by bgambey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "operation.h"
#include "strategy.h"
#include "libft.h"

#include "argparser.h"
#include "stack.h"

typedef struct s_push_swap_ctx
{
	t_strategy	stgy;
	int			is_bench;
	t_stack		a, b;
}	t_push_swap_ctx;

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

static int	stack_from_args(char **args, int argc, t_stack *stack)
{
	int	i;

	i = 0;
	while (i < argc)
	{
		if (
		i++;
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
	ctx->stgy.id = solve_method;
	ctx->is_bench = is_bench;
	if (stack_from_args(argv + ret, argc - ret, &ctx->a) < 0) // stacks allocated
		return (-1);
	return (0);
}

int	main(int argc, char **argv)
{
	//float		start_disorder;
	//int			i;
	t_strategy	*strategy;
	t_operation	*operation;
	int			method;
	int			is_bench;
	t_stack		stack;
	s_push_swap_ctx	ctx;

	ctx = {-1, 0, (t_stack) {0}, (t_stack) {0}};
	if (argc <= 1)
		return (0);
	if (parse_args(argc, argv, &ctx) < 0)
		return (ft_dprintf(2, "Error\n"), 1);
	// ctx.a.values && ctx.b.values are allocated (call destroy_stack())
	return (0);

	// Dead code, for now ...
	strategy = new_strategy();
	strategy->category = "Simple";
	strategy->complexity = "O(n2)";
	operation = new_operation();
	operation->sa = 1;
	operation->sb = 2;
	operation->ss = 3;
	operation->pa = 4;
	operation->pb = 5;
	operation->ra = 6;
	operation->rb = 7;
	operation->rr = 8;
	operation->rra = 9;
	operation->rrb = 10;
	operation->rrr = 11;
	//print_bench(40.58f, strategy, 20, operation);
	return (0);
}
