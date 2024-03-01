#include "simple_shell.h"

/**
* main - A function that checks the state of the simple shell
*
* Return: 0 on success
*/

int main(void)
{
/* checks the file descriptor to know the shell status */
if (isatty(STDIN_FILENO) == 1)
{
interactive_state();
}
return (0);
}
