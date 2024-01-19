#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
typedef struct var_struct
{
	char *arg;
	char *input_str;
	int SQ;
	FILE *file;
} global_v;

extern global_v arg_holder;
global_v arg_holder;

void nop(stack_t **stack, unsigned int line_no);
void make_buffer(char *file_name);
void opcode(char *command, unsigned int line_no, stack_t **stack);
void free_stack(stack_t **head);

void add(stack_t **stack, unsigned int line_no);
void pint(stack_t **stack, unsigned int line_no);
void pop(stack_t **stack, unsigned int line_no);
void swap(stack_t **stack, unsigned int line_no);
int isnum(char *str);
void stack_(stack_t **stack, stack_t *new_);
void pall(stack_t **stack, unsigned int line_no);
void push(stack_t **stack, unsigned int line_no);
void _div(stack_t **stack, unsigned int line_no);
void pstr(stack_t **stack, unsigned int line_no);
void rotl(stack_t **stack, unsigned int line_no);
void sub(stack_t **stack, unsigned int line_no);
void mod(stack_t **stack, unsigned int line_no);
void mul(stack_t **stack, unsigned int line_no);
void pchar(stack_t **stack, unsigned int line_no);
void rotr(stack_t **stack, unsigned int line_no);
void queue(stack_t **stack, stack_t *new_);

#endif
