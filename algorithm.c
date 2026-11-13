#include "algorithm.h"

t_algorithm	*new_algorithm(void)
{
	t_algorithm	*algorithm;

	algorithm = (t_algorithm *)malloc(sizeof(t_algorithm));
	return (algorithm);
}

#define TODO f

void f(t_stack *, t_op_list *) { *(size_t *) 0 = ft_dprintf(2, "WIP, aborting\n"); }

t_algorithm	*get_algorithms(void)
{
	static t_algorithm algorithms[] = {
		{SIMPLE, "Simple", "O(n2)", sort_simple},
		{MEDIUM, "Medium", "O(nSQRT(n))", TODO},
		{COMPLEX, "Complex", "O(nLOG(n))", TODO},
		{ADAPTATIVE, "Adaptative", nullptr, TODO},
		{-1, nullptr, nullptr, nullptr}
	};

	return (algorithms);
}

// Find algorithm matching given strategy
t_algorithm	*find_algorithm(t_strat_id strat)
{
	t_algorithm	*algos;

	algos = get_algorithms();
	while (algos->strat >= 0)
	{
		if (algos->strat == strat)
			return (algos);
		algos++;
	}
	return (nullptr);
}
