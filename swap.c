#include "monty.h"

/**
 * swap - swaps the top two elements of the stack
 * @stack: stack of memory
 * @line_no: line number
 */
void swap(stack_t **stack, unsigned int line_no)
{
	stack_t *current = NULL;
	int tmp = 0;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		printf("L%u: can't swap, stack too short\n", line_no);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	current = *stack;
	tmp = current->n;

	current->n = tmp;
	current->n = current->next->n;
	current->next->n = tmp;
}
