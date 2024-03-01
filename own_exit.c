#include "simple_shell.h"

/**
 * own_exit - Exits the shell.
 * @args: Arguments passed to the exit command (optional).
 *
 * Return: Always returns 0 to indicate successful execution.
 */

int own_exit(char **args)
{
if (args[1] != NULL)
{
int status = atoi(args[1]);
exit(status);
}
else
{
exit(EXIT_SUCCESS);
}
}

