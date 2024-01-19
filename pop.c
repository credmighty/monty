#include "monty.h"

/**
 * pop - removes the top element of the stack
 * @stack: stack of memory
 * @line_no: line number
 */
void pop(stack_t **stack, unsigned int line_no)
{
	stack_t *next = NULL;

	if (stack == NULL || *stack == NULL)
	{
		printf("L%u: can't pop an empty stack\n", line_no);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}

	next = (*stack)->next;
	free(*stack);
	*stack = next;
	if (*stack == NULL)
		return;
	(*stack)->prev = NULL;
}
