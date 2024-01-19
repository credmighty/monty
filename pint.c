#include "monty.h"
/**
 * pint - print at the top of the stack
 * @stack: stack of memory
 * @line_no: line number
 */
void pint(stack_t **stack, unsigned int line_no)
{
	if (stack == NULL || *stack == NULL)
	{
		printf("L%u: can't pint, stack empty", line_no);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
