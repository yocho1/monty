#include "monty.h"

/**
 * pstr - prints the string starting at the top of the stack
 * @stack: pointer to the stack head
 * @line_number: current line number
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *current;
	int value;
	(void)line_number;

	current = *stack;

	while (current != NULL)
	{
		value = current->n;

		/* Stop at 0 (null terminator) */
		if (value == 0)
			break;

		/* Stop if not in ASCII range */
		if (value < 0 || value > 127)
			break;

		printf("%c", value);
		current = current->next;
	}

	printf("\n");
}
