#include "simple_shell.h"

/**
 * read_line - Reads a line from stdin.
 *
 * Return: A pointer to the read line.
 */

char *read_line(void)
{
char *line = NULL;
size_t bufsize = 0;
ssize_t nread;

nread = getline(&line, &bufsize, stdin);
if (nread == -1)
{
if (feof(stdin))
{
/* End of file (Ctrl+D) encountered */
exit(EXIT_SUCCESS);
}
else
{
perror("read_line");
exit(EXIT_FAILURE);
}
}

/* Remove newline character, if present */
if (line[nread - 1] == '\n')
{
line[nread - 1] = '\0';
}

return (line);
}

