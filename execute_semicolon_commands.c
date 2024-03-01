#include "simple_shell.h"

/**
 * execute_semicolon_commands - Executes commands separated by semicolons.
 * @line: The command line input.
 *
 * Return: void.
 */
void execute_semicolon_commands(char *line)
{
char *token;
char *delimiters = ";";
char *line_copy = strdup(line);

if (line_copy == NULL)
{
fprintf(stderr, "Allocation error\n");
exit(EXIT_FAILURE);
}

token = strtok(line_copy, delimiters);
while (token != NULL)
{
execute_single_command(token);
token = strtok(NULL, delimiters);
}

free(line_copy);
}

