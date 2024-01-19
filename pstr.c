#include "monty.h"
/**
 * pstr -prints the string starting at the top of the stack
 * @stack: stack of the memory
 * @line_no: line number
 */
void pstr(stack_t **stack, unsigned int line_no)
{
	stack_t *current = NULL;

	(void) line_no;
	current = *stack;
	while (current != NULL)
	{
		if (current->n > 0 && isascii(current->n))
		{
			printf("%c", current->n);
			current = current->next;
		}
		else
			break;
	}
	printf("\n");
}
