#include "operation.h"
#include <stdlib.h>

t_operation	*new_operation(void)
{
	t_operation *operation;

	operation = (t_operation *)malloc(sizeof(t_operation));
	return (operation);
}