#include "monty.h"
/**
 * mod - computes the rest of the division of the second top element of the
 *	stack by the top element of the stack
 * @stack: stack of memory
 * @line_no: line number
 */
void mod(stack_t **stack, unsigned int line_no)
{
	stack_t *current = NULL;
	int res = 0;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		printf("L%u: can't mod, stack too short\n", line_no);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		printf("L%u: division by zero\n", line_no);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	current = *stack;
	res = current->next->n % current->n;
	pop(stack, line_no);
	(*stack)->n = res;
}
