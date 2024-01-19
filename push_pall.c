#include "monty.h"

/**
 * isnum - check if string is a number
 * @str: string arg
 * Return: 0 if false, 1 if true
 */
int isnum(char *str)
{
	if (str == NULL)
		return (0);
	if (*str == '-')
		str++;
	while (str)
	{
		if (!isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

/**
 * push - pushes an element to the stack
 * @stack: stack memory
 * @line_no: line number
 */
void push(stack_t **stack, unsigned int line_no)
{
	if (stack == NULL)
		exit(EXIT_FAILURE);
	if (!(isnum(arg_holder.arg)))
	{
		printf("L%u: usage: push integer", line_no);
	}
}

/**
 * pall - print out all the stack
 * @stack: stack memory
 * @line_no: line number
 */
void pall(stack_t **stack, unsigned int line_no)
{
	stack_t *current;

	(void) line_no;
	if (*stack == NULL)
		return;
	current = *stack;
	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}

/**
 * stack - LIFO/FILO data type
 * @stack: stack of the memory
 * @new_: new element to add
 */
void stack(stack_t **stack, stack_t *new_)
{
	new_->n = atoi(arg_holder.arg);
	if (*stack == NULL)
	{
		new_->prev = NULL;
		new_->next = NULL;
		*stack = new_;
	}
	else
	{
		(*stack)->prev = new_;
		new_->next = *stack;
		new_->prev = NULL;
		*stack = new_;
	}
}
