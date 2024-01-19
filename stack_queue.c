#include "monty.h"

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

/**
 * queue - FIFO data type
 * @stack: stack of memory
 * @new_: new element to add
 */
void queue(stack_t **stack, stack_t *new_)
{
	stack_t *holder;

	new_->n = atoi(arg_holder.arg);
	new_->next = NULL;
	if (*stack == NULL)
	{
		new_->prev = NULL;
		*stack = new_;
	}
	else
	{
		holder = *stack;
		while (holder->next != NULL)
		{
			holder = holder->next;
		}
		holder->next = new_;
		new_->prev = holder;
	}
}
