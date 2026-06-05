#include "monty.h"

/**
 * add - adds the top two elements of the stack
 * @stack: pointer to the stack head
 * @line_number: current line number
 */
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *first, *second;
	int sum;

	if (!stack || !*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	first = *stack;
	second = (*stack)->next;

	sum = first->n + second->n;

	/* Remove the top element */
	*stack = second;
	second->prev = NULL;

	/* Update the new top with the sum */
	(*stack)->n = sum;

	/* Free the removed node */
	free(first);
}
