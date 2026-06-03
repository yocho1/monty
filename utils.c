#include "monty.h"

/**
 * is_integer - checks if a string represents an integer
 * @str: string to check
 *
 * Return: 1 if integer, 0 otherwise
 */
int is_integer(char *str)
{
    if (!str || *str == '\0')
        return (0);
    
    if (*str == '-' || *str == '+')
        str++;
    
    if (*str == '\0')
        return (0);
    
    while (*str)
    {
        if (!isdigit(*str))
            return (0);
        str++;
    }
    
    return (1);
}

/**
 * free_stack - frees the entire stack
 * @stack: pointer to the stack head
 */
void free_stack(stack_t **stack)
{
    stack_t *temp;

    while (*stack)
    {
        temp = *stack;
        *stack = (*stack)->next;
        free(temp);
    }
}
