#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element
 * @next: points to the next element
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* Core opcode functions */
void push(stack_t **stack, unsigned int line_number, char *arg);
void pall(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
/* Executor functions */
void exec_push(stack_t **stack, char *arg, unsigned int line_number,
	char *line, FILE *file);
void exec_pall(stack_t **stack, unsigned int line_number,
	char *line, FILE *file);
void exec_pint(stack_t **stack, unsigned int line_number,
	char *line, FILE *file);
void exec_unknown(stack_t **stack, char *opcode, unsigned int line_number,
	char *line, FILE *file);
void exec_pop(stack_t **stack, unsigned int line_number,
	char *line, FILE *file);
/* Utility functions */
void free_stack(stack_t **stack);
int is_integer(char *str);
void process_line(stack_t **stack, char *line,
	unsigned int line_number, FILE *file);

#endif /* MONTY_H */
