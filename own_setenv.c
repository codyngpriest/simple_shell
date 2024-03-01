#include "simple_shell.h"

/**
* own_setenv - sets the environment
* @args: the arguments
*
* Return: 1 on success
*/

int own_setenv(char **args)
{
/* Check if the command syntax is correct */
if (args[1] == NULL || args[2] == NULL)
{
fprintf(stderr, "Usage: setenv VARIABLE VALUE\n");
return (1);
}

/* Call setenv to initialize or modify the environment variable */
if (setenv(args[1], args[2], 1) != 0)
{
perror("setenv");
return (1);
}
return (0);
}
