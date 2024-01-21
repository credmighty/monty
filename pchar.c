#include "monty.h"
/**
 * pchar - prints the char at the top of the stack, followed by a new line
 * @stack: stack of the memory
 * @line_no: line number
 */
void pchar(stack_t **stack, unsigned int line_no)
{
	if (stack == NULL || *stack == NULL)
	{
		printf("L%u: can't pchar, stack empty\n", line_no);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n < 0 || (*stack)->n > 127)
	{
		printf("L%u: can't pchar, value out of range", line_no);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (*stack)->n);
}
