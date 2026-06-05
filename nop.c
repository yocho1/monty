#include "monty.h"

/**
 * nop - does nothing
 * @stack: pointer to the stack head (unused)
 * @line_number: current line number (unused)
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	/* This opcode does absolutely nothing */
}
