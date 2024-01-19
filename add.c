#include "monty.h"
/**
 * add - adds the top 2 elements of the stack
 * @stack: stack of the memmory
 * @line_no: line number
 */
void add(stack_t **stack, unsigned int line_no)
{
	stack_t *current = NULL;
	int sum2Tp = 0;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		printf("L%u: can't add, stack too short\n", line_no);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	current = *stack;
	sum2Tp = current->n + current->next->n;
	pop(stack, line_no);
	(*stack)->n = sum2Tp;
}
