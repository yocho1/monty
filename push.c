#include "monty.h"

/**
 * push - pushes an element to the stack or queue
 * @stack: pointer to the stack head
 * @line_number: current line number (unused)
 * @arg: argument (integer to push)
 */
void push(stack_t **stack, unsigned int line_number, char *arg)
{
	stack_t *new_node;
	stack_t *current;
	int value;
	(void)line_number;

	value = atoi(arg);

	new_node = malloc(sizeof(stack_t));
	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = value;
	new_node->next = NULL;
	new_node->prev = NULL;

	/* If stack is empty */
	if (*stack == NULL)
	{
		*stack = new_node;
		return;
	}

	/* Mode 0 = Stack (LIFO) - add to top */
	if (mode == 0)
	{
		new_node->next = *stack;
		(*stack)->prev = new_node;
		*stack = new_node;
	}
	/* Mode 1 = Queue (FIFO) - add to bottom */
	else
	{
		current = *stack;
		while (current->next != NULL)
			current = current->next;
		current->next = new_node;
		new_node->prev = current;
	}
}
