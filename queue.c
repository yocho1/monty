#include "monty.h"

/**
 * queue_mode - sets the format to queue (FIFO)
 * @stack: pointer to the stack head (unused)
 * @line_number: current line number (unused)
 */
void queue_mode(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	mode = 1;  /* 1 = queue mode */
}
