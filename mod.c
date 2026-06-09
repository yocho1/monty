#include "monty.h"

/**
 * mod - computes the remainder of the second top element divided by top
 * @stack: pointer to the stack head
 * @line_number: current line number
 */
void mod(stack_t **stack, unsigned int line_number)
{
	stack_t *first, *second;
	int result;

	if (!stack || !*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	first = *stack;
	second = (*stack)->next;

	if (first->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	result = second->n % first->n;

	/* Remove the top element */
	*stack = second;
	second->prev = NULL;

	/* Update the new top with the result */
	(*stack)->n = result;

	/* Free the removed node */
	free(first);
}
