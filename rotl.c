#include "monty.h"
/**
 * rotl - rotates the stack to the top
 * @stack: stack of the memory
 * @line_no: line number
 */
void rotl(stack_t **stack, unsigned int line_no)
{
	stack_t *first = NULL, *last = NULL;

	(void) line_no;
	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	first = last = *stack;
	while (last->next != NULL)
		last = last->next;

	last->next = first;
	first->prev = last;
	*stack = first->next;
	(*stack)->prev->next = NULL;
	(*stack)->prev = NULL;
}
