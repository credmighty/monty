#include "monty.h"

/**
 * main - program entry
 * @argc: arguments count
 * @argv: arguments vector
 * Return: EXIT SUCCESS
 */
int main(int argc, char **argv)
{
	if (argc != 2)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	make_buffer(argv[1]);
	return (EXIT_SUCCESS);
}

/**
 * opcode - check for operation
 * @command: command input
 * @line_no: line number
 * @stack: stack of memory
 */
void opcode(char *command, unsigned int line_no, stack_t **stack)
{
	int i = 0;
	instruction_t ops[] = {
		{"push", push},	{"pall", pall},	{"pint", pint},
		{"pop", pop}, {"swap", swap}, {"add", add},
		{"nop", nop}, {"sub", sub}, {"div", _div},
		{"mod", mod}, {"pchar", pchar},	{"mul", mul},
		{"pstr", pstr}, {"rotr", rotr}, {"rotl", rotl},	{NULL, NULL}
	};

	if (command[0] == '#')
		return;
	if (strcmp(command, "stack") == 0)
	{
		arg_holder.SQ = 1;
		return;
	}
	if (strcmp(command, "queue") == 0)
	{
		arg_holder.SQ = 0;
		return;
	}
	while (ops[i].opcode != NULL)
	{
		if (strcmp(ops[i].opcode, command) == 0)
		{
			ops[i].f(stack, line_no);
			return;
		}
		i++;
	}
	printf("L%d: unknown instruction %s\n", line_no, command);
	free_stack(stack);
	exit(EXIT_FAILURE);
}
#include "monty.h"
/**
 * free_stack - free the stack and the str input
 * @head: input list pointer
 */
void free_stack(stack_t **head)
{
	stack_t *current;

	if (head == NULL)
		return;
	free(arg_holder.input_str);
	fclose(arg_holder.file);
	while (*head != NULL)
	{
		current = (*head)->next;
		free(*head);
		*head = current;
	}
}

/**
 * make_buffer - make the buffer and parse through the file
 * @file_name: name of the file
 */
void make_buffer(char *file_name)
{
	size_t size = 0;
	FILE *file_input;
	char *str = NULL;
	unsigned int line_no = 1;
	stack_t *stack = NULL;
	char *command = NULL;

	file_input = fopen(file_name, "r");
	if (file_input == NULL)
	{
		printf("Error: Can't open file %s\n", file_name);
		exit(EXIT_FAILURE);
	}
	arg_holder.file = file_input;
	arg_holder.SQ = 1;
	while (getline(&str, &size, file_input) != -1)
	{
		arg_holder.input_str = str;
		if (*str == '\n')
		{
			line_no++;
			continue;
		}
		command = strtok(str, "\n\t ");
		if (command == NULL)
		{
			line_no++;
			continue;
		}
		arg_holder.arg = strtok(NULL, "\n\t ");
		opcode(command, line_no, &stack);
		line_no++;
	}
	free_stack(&stack);
}
