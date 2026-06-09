#include "monty.h"

/**
 * stack_mode - sets the format to stack (LIFO)
 * @stack: pointer to the stack head (unused)
 * @line_number: current line number (unused)
 */
void stack_mode(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	mode = 0;  /* 0 = stack mode */
}
