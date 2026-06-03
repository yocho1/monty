#include "monty.h"

/**
 * process_line - processes a single line of Monty bytecode
 * @stack: pointer to the stack head
 * @line: line to process
 * @line_number: current line number
 * @file: file pointer
 */
void process_line(stack_t **stack, char *line,
	unsigned int line_number, FILE *file)
{
	char *opcode, *arg, *trimmed;

	trimmed = line;
	while (*trimmed == ' ' || *trimmed == '\t')
		trimmed++;

	if (*trimmed == '\n' || *trimmed == '\0' || *trimmed == '#')
		return;

	trimmed[strcspn(trimmed, "\n")] = '\0';

	opcode = strtok(trimmed, " \t");
	if (!opcode)
		return;

	arg = strtok(NULL, " \t");

	if (strcmp(opcode, "push") == 0)
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
	else if (strcmp(opcode, "pall") == 0)
	{
		pall(stack, line_number);
	}
	else if (strcmp(opcode, "pint") == 0)
	{
		pint(stack, line_number);
	}
	else if (strcmp(opcode, "pop") == 0)
	{
		pop(stack, line_number);
	}
	else
	{
		fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
		free(line);
		fclose(file);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
}

/**
 * main - entry point for Monty interpreter
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure
 */
int main(int argc, char *argv[])
{
	FILE *file;
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	unsigned int line_number = 0;
	stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while ((read = getline(&line, &len, file)) != -1)
	{
		line_number++;
		process_line(&stack, line, line_number, file);
	}

	free(line);
	fclose(file);
	free_stack(&stack);
	return (EXIT_SUCCESS);
}
