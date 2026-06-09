#include "monty.h"

/**
 * rotr - rotates the stack to the bottom
 * @stack: pointer to the stack head
 * @line_number: current line number
 */
void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *first, *last, *second_last;
	(void)line_number;

	/* If stack is empty or has only one element, do nothing */
	if (!stack || !*stack || !(*stack)->next)
		return;

	first = *stack;        /* Top element */
	last = first;

	/* Find the last node and second-to-last node */
	while (last->next != NULL)
	{
		second_last = last;
		last = last->next;
	}

	/* Remove last node */
	second_last->next = NULL;
	last->prev = NULL;

	/* Move last node to top */
	last->next = first;
	first->prev = last;

	/* Update stack head */
	*stack = last;
}
