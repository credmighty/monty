#include "monty.h"
/**
 * _div - divides the 2nd top element of the stack by the top element
 * @stack: stack of the memory
 * @line_no: line number
 */
void _div(stack_t **stack, unsigned int line_no)
{
	stack_t *current = NULL;
	int res = 0;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		printf("L%u: can't div, stack too short\n", line_no);
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
	res = current->next->n / current->n;
	pop(stack, line_no);
	(*stack)->n = res;
}

