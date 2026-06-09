#include "monty.h"

/**
 * rotl - rotates the stack to the top
 * @stack: pointer to the stack head
 * @line_number: current line number
 */
void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *first, *last, *second;
	(void)line_number;

	/* If stack is empty or has only one element, do nothing */
	if (!stack || !*stack || !(*stack)->next)
		return;

	first = *stack;        /* Top element */
	second = first->next;  /* Second element */

	/* Find the last node */
	last = first;
	while (last->next != NULL)
		last = last->next;

	/* Move top to bottom */
	first->next = NULL;
	first->prev = last;
	last->next = first;

	/* New top is second element */
	second->prev = NULL;
	*stack = second;
}
