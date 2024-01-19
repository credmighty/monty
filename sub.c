#include "monty.h"
/**
 * sub - subtracts the top element of the stack from the
 *	second top element of the stack
 * @stack: stack of memory
 * @line_no: line number
 */
void sub(stack_t **stack, unsigned int line_no)
{
	stack_t *current = NULL;
	int total = 0;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		printf("L%u: can't sub, stack too short\n", line_no);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	current = *stack;
	total = current->next->n - current->n;
	pop(stack, line_no);
	(*stack)->n = total;
}
