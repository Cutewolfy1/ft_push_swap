#include "strategy.h"
#include <stdlib.h>

t_strategy	*new_strategy(void)
{
	t_strategy	*strategy;

	strategy = (t_strategy *)malloc(sizeof(t_strategy));
	return (strategy);
}
