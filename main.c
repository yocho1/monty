#include "monty.h"

/**
 * main - entry point for Monty interpreter
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure
 */
int main(int argc, char *argv[])
{
    FILE *file;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    unsigned int line_number = 0;
    stack_t *stack = NULL;
    char *opcode, *arg;

    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }

    file = fopen(argv[1], "r");
    if (!file)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    while ((read = getline(&line, &len, file)) != -1)
    {
        line_number++;
        
        /* Remove newline */
        if (line[read - 1] == '\n')
            line[read - 1] = '\0';
        
        /* Skip empty lines */
        if (line[0] == '\0')
            continue;
        
        /* Skip comment lines */
        if (line[0] == '#')
            continue;
        
        /* Parse opcode and argument */
        opcode = strtok(line, " \t");
        if (!opcode)
            continue;
        
        arg = strtok(NULL, " \t");
        
        /* Execute the opcode */
        if (strcmp(opcode, "push") == 0)
        {
            if (!arg || !is_integer(arg))
            {
                fprintf(stderr, "L%u: usage: push integer\n", line_number);
                free(line);
                fclose(file);
                free_stack(&stack);
                exit(EXIT_FAILURE);
            }
            push(&stack, line_number, arg);
        }
        else if (strcmp(opcode, "pall") == 0)
        {
            pall(&stack, line_number);
        }
        else
        {
            fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
            free(line);
            fclose(file);
            free_stack(&stack);
            exit(EXIT_FAILURE);
        }
    }

    free(line);
    fclose(file);
    free_stack(&stack);
    return (EXIT_SUCCESS);
}
