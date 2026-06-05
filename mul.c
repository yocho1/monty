#include "monty.h"

/**
 * mul - multiplies the second top element by the top element
 * @stack: pointer to the stack head
 * @line_number: current line number
 */
void mul(stack_t **stack, unsigned int line_number)
{
	stack_t *first, *second;
	int result;

	if (!stack || !*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	first = *stack;
	second = (*stack)->next;

	result = second->n * first->n;

	/* Remove the top element */
	*stack = second;
	second->prev = NULL;

	/* Update the new top with the result */
	(*stack)->n = result;

	/* Free the removed node */
	free(first);
}
