#include "monty.h"
/**
 * mul - multiplies the second top element of the stack with the top element
 * @stack: stack of the memory
 * @line_no: line number
 */
void mul(stack_t **stack, unsigned int line_no)
{
	stack_t *current = NULL;
	int res = 0;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		printf("L%u: can't mul, stack too short\n", line_no);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	current = *stack;
	res = current->next->n * current->n;
	pop(stack, line_no);
	(*stack)->n = res;
}
