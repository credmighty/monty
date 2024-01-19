#include "monty.h"
/**
 * rotr - rotates the stack to the bottom
 * @stack: stack of the memory
 * @line_no: line number
 */
void rotr(stack_t **stack, unsigned int line_no)
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
	*stack = last;
	(*stack)->prev->next = NULL;
	(*stack)->prev = NULL;
}
