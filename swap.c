#include "monty.h"

/**
 * swap - swaps the top two elements of the stack
 * @stack: pointer to the stack head
 * @line_number: current line number
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *first, *second;
	int temp;

	if (!stack || !*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	first = *stack;
	second = (*stack)->next;

	temp = first->n;
	first->n = second->n;
	second->n = temp;
}
