#include "simple_shell.h"

/**
 * execute_single_command - Executes a single command.
 * @command: The command to execute.
 *
 * Return: void.
 */

void execute_single_command(char *command)
{
char **args = split_line(command, " ");
int status = execute_arguments(args);
free(args);

if (status == 0)
{
fprintf(stderr, "Error executing command: %s\n", command);
}
}
