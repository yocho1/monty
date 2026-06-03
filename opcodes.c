#include "monty.h"

/**
 * exec_pint - executes pint opcode
 * @stack: pointer to stack
 * @line_number: line number
 * @line: line buffer (unused)
 * @file: file pointer (unused)
 */
void exec_pint(stack_t **stack, unsigned int line_number,
	char *line, FILE *file)
{
	(void)line;
	(void)file;
	pint(stack, line_number);
}

/**
 * exec_push - executes push opcode
 * @stack: pointer to stack
 * @arg: argument
 * @line_number: line number
 * @line: line buffer
 * @file: file pointer
 */
void exec_push(stack_t **stack, char *arg, unsigned int line_number,
	char *line, FILE *file)
{
	if (!arg || !is_integer(arg))
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		free(line);
		fclose(file);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	push(stack, line_number, arg);
}

/**
 * exec_pall - executes pall opcode
 * @stack: pointer to stack
 * @line_number: line number
 * @line: line buffer (unused)
 * @file: file pointer (unused)
 */
void exec_pall(stack_t **stack, unsigned int line_number,
	char *line, FILE *file)
{
	(void)line;
	(void)file;
	pall(stack, line_number);
}

/**
 * exec_unknown - handles unknown opcode
 * @stack: pointer to stack
 * @opcode: unknown opcode
 * @line_number: line number
 * @line: line buffer
 * @file: file pointer
 */
void exec_unknown(stack_t **stack, char *opcode, unsigned int line_number,
	char *line, FILE *file)
{
	fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
	free(line);
	fclose(file);
	free_stack(stack);
	exit(EXIT_FAILURE);
}
