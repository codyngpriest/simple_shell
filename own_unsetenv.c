#include "simple_shell.h"

/**
* own_unsetenv - unsets the environment
* @args: the arguments
*
* Return: 1 on success
*/

int own_unsetenv(char **args)
{
if (args[1] == NULL)
{
fprintf(stderr, "Usage: unsetenv VARIABLE\n");
return (1);
}

if (unsetenv(args[1]) != 0)
{
perror("unsetenv");
return (1);
}

return (0);
}
