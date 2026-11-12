#include "strategy.h"
#include <stdlib.h>

t_strategy	*new_strategy(void)
{
	t_strategy	*strategy;

	strategy = (t_strategy *)malloc(sizeof(t_strategy));
	return (strategy);
}

t_strategy	*get_strategies(void)
{
	static t_strategy strategies[] = {
		{SIMPLE, "Simple", "O(n2)"},
		{MEDIUM, "Medium", "O(nSQRT(n))"},
		{COMPLEX, "Complex", "O(nLOG(n))"},
		{ADAPTATIVE, "Adaptative", nullptr},
	};

	return (strategies);
}
