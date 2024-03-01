#include "simple_shell.h"

/**
 * own_env - function that prints environment variables
 * @args: arguments
 *
 * Return: 1 on success, 0 otherwise
 */

int own_env(char **args)
{
int i = 0;

(void)args;
while (environ[i] != NULL)
{
printf("%s\n", environ[i]);
i++;
}

return (1);
}
