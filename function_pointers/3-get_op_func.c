#include <string.h>
#include "3-calc.h"

/**
 * get_op_func - selects the function that does an operation
 * @s: the operator passed as argument to the program
 *
 * Return: pointer to the function matching s, or NULL when none matches
 */
int (*get_op_func(char *s))(int, int)
{
	op_t ops[] = {
		{"+", op_add},
		{"-", op_sub},
		{"*", op_mul},
		{"/", op_div},
		{"%", op_mod},
		{NULL, NULL}
	};
	int i;

	i = 0;
	while (ops[i].op != NULL && strcmp(ops[i].op, s) != 0)
		i++;
	return (ops[i].f);
}
